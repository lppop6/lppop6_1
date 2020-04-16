#include "control_test.h"

control_test::control_test(QWidget* parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	//设置分裂器
	//QImage img (ui.lbl_Map_Show->width(), ui.lbl_Map_Show->height(),QImage::Format_ARGB32);
	ui.splitter->setStretchFactor(0, 8);
	ui.splitter->setStretchFactor(1, 1);
	//设置按钮宽度
	ui.btn_Reset->setFixedWidth(150);
	ui.btn_start->setFixedWidth(150);
	//固定死窗口
	setWindowFlags(0);
	setFixedSize(665, 772);
	//设置轨迹坐标显示的初始值
	//X_Before = 15;
	//Y_Before = 515;

	init_Map();												//初始化地图

	con604.Init();											//初始化控制器
	myT = new QTimer(this);									//new一个定时器
	//定时器，用来显示速度，与相对位移
	connect(myT, &QTimer::timeout,
		[=] {
			ui.lbl_Displacement_Relative->setText(QString::number(con604.Get_S(), 10, 2));
			ui.lbl_Relative_V->setText(QString::number(con604.Get_V(), 10, 2));
		}
	);


	//ui.sld_X->setValue
	//connect(ui.spb_X, &QSpinBox::valueChanged, ui.sld_X, &QSlider::setValue);
	//连接Slider与SpinBox,当两者有值改变的时候发送信号给Map_Show_Thread线程
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

	//开启Map_Show_Thread线程
	map_Thread = new Map_Show_Thread;
	thread = new QThread(this);
	map_Thread->moveToThread(thread);
	thread->start();

	//窗口关闭的时候运行map_close函数
	connect(this, &QMainWindow::destroyed, this, &control_test::map_Close);

	//接收到线程Map_Show_Thread传来的send_Map信号（带有QImage），运行行update_Map函数
	connect(map_Thread, &Map_Show_Thread::send_Map, this, &control_test::update_Map);

	//接收从自定义控件传来的X，Y坐标，并显示
	connect(ui.lbl_Map_Show, &LabelMap::send_X_Y, this, &control_test::set_X_Y);


	//显示轨迹
	connect(ui.btn_Reset, &QPushButton::clicked, this, &control_test::track_Reset);

	connect(ui.btn_start, &QPushButton::clicked, this, &control_test::show_Track);

	//运动控制
	connect(ui.btn_Reset, &QPushButton::clicked, this, &control_test::move_Reset);
	connect(ui.btn_start, &QPushButton::clicked, this, &control_test::move_Start);
	connect(ui.btn_Change_V, &QPushButton::clicked, this, &control_test::set_V);
}

//鼠标设置位置，将lbl_Map_Show提升为LabelMap，获取点击事件
void control_test::set_X_Y(int x, int y) {
	ui.spb_X->setValue((x - 15) / 5);
	ui.spb_Y->setValue((515 - y) / 5);
}

//地图初始化
void control_test::init_Map() {
	//设置Map图标，并且显示第一幅图标
	QImage img;
	img.load(":./DP/Resources/Map.png");
	img = img.scaled(500, 500);
	QImage imgUnder(530, 530, QImage::Format_ARGB32);
	QImage icon = QImage(":./DP/Resources/Position.png");
	icon = icon.scaled(30, 30);
	Position = icon;							//传输全局的当前位置图标
	QImage preIcon = QImage(":./DP/Resources/PrePosition.png");
	preIcon = preIcon.scaled(30, 30);
	prePosition = preIcon;						//传输全局的先前位置图标
	QPainter p;
	p.begin(&imgUnder);
	p.drawImage(15, 15, img);
	gridMap = imgUnder;							//传输全局网格地图
	p.drawImage(0, 500, icon);
	p.end();
	//ui.label->setPixmap(QPixmap::fromImage(img));
	X_Before = 15;								//设置先前X值为原点		即轨迹坐标显示的初始值
	Y_Before = 515;								//设置先前Y值为原点		即轨迹坐标显示的初始值

	ui.lbl_Map_Show->setPixmap(QPixmap::fromImage(imgUnder));
}

//重置轨迹
void control_test::track_Reset() {
	isFirstShow = true;
	init_Map();
	ui.spb_X->setValue(0);
	ui.spb_Y->setValue(0);
}


//关闭地图
void control_test::map_Close() {
	thread->quit();
	thread->wait();
	delete map_Thread;
}


//更新地图
void control_test::update_Map(QImage tmp) {
	ui.lbl_Map_Show->setPixmap(QPixmap::fromImage(tmp));
	update();
}


//显示轨迹
void control_test::show_Track() {
	QImage temp;
	map_Thread->show_Track(ui.spb_X->value(), ui.spb_Y->value(), X_Before, Y_Before);
	X_Before = 5 * (ui.spb_X->value()) + 15;
	Y_Before = 515 - 5 * ui.spb_Y->value();
}


//运动复位
void control_test::move_Reset() {
	con604.Reset();
	if (myT->isActive() == true) {
		myT->stop();
	}
}

//开始运动
void control_test::move_Start() {
	if (myT->isActive() == false) {
		myT->start(1000);					//500ms的定时器，用来实时显示轴的速度
	}
	double x = ui.spb_X->value();
	double y = ui.spb_Y->value();
	con604.Move(x, y);
}

//设置速度
void control_test::set_V() {
	double v = ui.dspn_V->value();
	con604.Set_V(v);
}


////求坐标点的最大公约数（用于显示轨迹）
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
