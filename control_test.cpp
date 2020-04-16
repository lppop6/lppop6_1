#include "control_test.h"

control_test::control_test(QWidget* parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	//���÷�����
	//QImage img (ui.lbl_Map_Show->width(), ui.lbl_Map_Show->height(),QImage::Format_ARGB32);
	ui.splitter->setStretchFactor(0, 8);
	ui.splitter->setStretchFactor(1, 1);
	//���ð�ť���
	ui.btn_Reset->setFixedWidth(150);
	ui.btn_start->setFixedWidth(150);
	//�̶�������
	setWindowFlags(0);
	setFixedSize(665, 772);
	//���ù켣������ʾ�ĳ�ʼֵ
	//X_Before = 15;
	//Y_Before = 515;

	init_Map();												//��ʼ����ͼ

	con604.Init();											//��ʼ��������
	myT = new QTimer(this);									//newһ����ʱ��
	//��ʱ����������ʾ�ٶȣ������λ��
	connect(myT, &QTimer::timeout,
		[=] {
			ui.lbl_Displacement_Relative->setText(QString::number(con604.Get_S(), 10, 2));
			ui.lbl_Relative_V->setText(QString::number(con604.Get_V(), 10, 2));
		}
	);


	//ui.sld_X->setValue
	//connect(ui.spb_X, &QSpinBox::valueChanged, ui.sld_X, &QSlider::setValue);
	//����Slider��SpinBox,��������ֵ�ı��ʱ�����źŸ�Map_Show_Thread�߳�
	connect(ui.spb_X, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int i) {
			ui.sld_X->setValue(i);
			map_Thread->map_update(i, ui.sld_Y->value());
		});
	connect(ui.spb_Y, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int i) {
			ui.sld_Y->setValue(i);
			map_Thread->map_update(ui.sld_X->value(), i);
		});
	connect(ui.sld_X, QOverload<int>::of(&QSlider::valueChanged),
		[=](int i) {
			ui.spb_X->setValue(i);
			map_Thread->map_update(i, ui.sld_Y->value());
		});
	connect(ui.sld_Y, QOverload<int>::of(&QSlider::valueChanged),
		[=](int i) {
			ui.spb_Y->setValue(i);
			map_Thread->map_update(ui.sld_X->value(), i);
		});

	//����Map_Show_Thread�߳�
	map_Thread = new Map_Show_Thread;
	thread = new QThread(this);
	map_Thread->moveToThread(thread);
	thread->start();

	//���ڹرյ�ʱ������map_close����
	connect(this, &QMainWindow::destroyed, this, &control_test::map_Close);

	//���յ��߳�Map_Show_Thread������send_Map�źţ�����QImage����������update_Map����
	connect(map_Thread, &Map_Show_Thread::send_Map, this, &control_test::update_Map);

	//���մ��Զ���ؼ�������X��Y���꣬����ʾ
	connect(ui.lbl_Map_Show, &LabelMap::send_X_Y, this, &control_test::set_X_Y);


	//��ʾ�켣
	connect(ui.btn_Reset, &QPushButton::clicked, this, &control_test::track_Reset);

	connect(ui.btn_start, &QPushButton::clicked, this, &control_test::show_Track);

	//�˶�����
	connect(ui.btn_Reset, &QPushButton::clicked, this, &control_test::move_Reset);
	connect(ui.btn_start, &QPushButton::clicked, this, &control_test::move_Start);
	connect(ui.btn_Change_V, &QPushButton::clicked, this, &control_test::set_V);
}

//�������λ�ã���lbl_Map_Show����ΪLabelMap����ȡ����¼�
void control_test::set_X_Y(int x, int y) {
	ui.spb_X->setValue((x - 15) / 5);
	ui.spb_Y->setValue((515 - y) / 5);
}

//��ͼ��ʼ��
void control_test::init_Map() {
	//����Mapͼ�꣬������ʾ��һ��ͼ��
	QImage img;
	img.load(":./DP/Resources/Map.png");
	img = img.scaled(500, 500);
	QImage imgUnder(530, 530, QImage::Format_ARGB32);
	QImage icon = QImage(":./DP/Resources/Position.png");
	icon = icon.scaled(30, 30);
	Position = icon;							//����ȫ�ֵĵ�ǰλ��ͼ��
	QImage preIcon = QImage(":./DP/Resources/PrePosition.png");
	preIcon = preIcon.scaled(30, 30);
	prePosition = preIcon;						//����ȫ�ֵ���ǰλ��ͼ��
	QPainter p;
	p.begin(&imgUnder);
	p.drawImage(15, 15, img);
	gridMap = imgUnder;							//����ȫ�������ͼ
	p.drawImage(0, 500, icon);
	p.end();
	//ui.label->setPixmap(QPixmap::fromImage(img));
	X_Before = 15;								//������ǰXֵΪԭ��		���켣������ʾ�ĳ�ʼֵ
	Y_Before = 515;								//������ǰYֵΪԭ��		���켣������ʾ�ĳ�ʼֵ

	ui.lbl_Map_Show->setPixmap(QPixmap::fromImage(imgUnder));
}

//���ù켣
void control_test::track_Reset() {
	isFirstShow = true;
	init_Map();
	ui.spb_X->setValue(0);
	ui.spb_Y->setValue(0);
}


//�رյ�ͼ
void control_test::map_Close() {
	thread->quit();
	thread->wait();
	delete map_Thread;
}


//���µ�ͼ
void control_test::update_Map(QImage tmp) {
	ui.lbl_Map_Show->setPixmap(QPixmap::fromImage(tmp));
	update();
}


//��ʾ�켣
void control_test::show_Track() {
	QImage temp;
	map_Thread->show_Track(ui.spb_X->value(), ui.spb_Y->value(), X_Before, Y_Before);
	X_Before = 5 * (ui.spb_X->value()) + 15;
	Y_Before = 515 - 5 * ui.spb_Y->value();
}


//�˶���λ
void control_test::move_Reset() {
	con604.Reset();
	if (myT->isActive() == true) {
		myT->stop();
	}
}

//��ʼ�˶�
void control_test::move_Start() {
	if (myT->isActive() == false) {
		myT->start(1000);					//500ms�Ķ�ʱ��������ʵʱ��ʾ����ٶ�
	}
	double x = ui.spb_X->value();
	double y = ui.spb_Y->value();
	con604.Move(x, y);
}

//�����ٶ�
void control_test::set_V() {
	double v = ui.dspn_V->value();
	con604.Set_V(v);
}


////�����������Լ����������ʾ�켣��
//int control_test::get_Max_Com_Divisor(int x,int y) {
//	while (true) {
//		if (x > y) {
//			x -= y;
//		}
//		else if (x < y) {
//			y -= x;
//		}
//		else {
//			return x;
//		}
//	}
//}
//
//void control_test::show_Track() {
//	int com = get_Max_Com_Divisor(100,100);
//	std::vector<bool> tempVec;
//	tempVec = map_Thread->get_Track(com,100,100);
//	map_Thread->show_Track(tempVec);
//}
