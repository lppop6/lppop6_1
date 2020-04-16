#include "DP.h"

using namespace cv;
extern QString fileNameIQA;		//���ڴ��ݵ������ĸ��ļ�����IQA

DP::DP(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//���ó�ʼ��������ֵ
	ui.splitter->setStretchFactor(0, 5);
	ui.splitter->setStretchFactor(1, 1);
	//�����ʼ���������豸������в�������İ���ȫΪenable
	ui.btn_close->setEnabled(false);
	ui.btn_end_grabing->setEnabled(false);
	ui.btn_open->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
	//��ʼ����֤���ֻ����һ�εı�־��,������رյ�ʱ���ٽ�����λtrue
	isStartCamera = true;
	//�������ź����
	connect(ui.btn_search, &QPushButton::clicked, this, &DP::on_btn_search_click);
	connect(ui.btn_close, &QPushButton::clicked, this, &DP::on_btn_close_click);
	connect(ui.btn_get_param, &QPushButton::clicked, this, &DP::on_btn_get_param_click);
	connect(ui.btn_end_grabing, &QPushButton::clicked, this, &DP::on_btn_end_grabing_click);
	connect(ui.btn_open, &QPushButton::clicked, this, &DP::on_btn_open_click);
	connect(ui.btn_save_BMP, &QPushButton::clicked, this, &DP::on_btn_save_BMP_click);
	connect(ui.btn_save_JPG, &QPushButton::clicked, this, &DP::on_btn_save_JPG_click);
	connect(ui.btn_set_param, &QPushButton::clicked, this, &DP::on_btn_set_param_click);
	connect(ui.btn_start_grabing, &QPushButton::clicked, this, &DP::on_btn_start_grabing_click);

	//����˵��е��������ۣ�Ȼ�����ѡ������ĳһ���ļ�
	connect(ui.action2, &QAction::triggered,
		[=] {
			QString fileName = QFileDialog::getOpenFileName(
				this,
				tr("open a file."),
				filePath + "/Pic",
				tr("images(*.png *jpg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
			if (fileName.isEmpty() == false) {
				emit send_Pic_Path(fileName);		//�����źŴ����ļ���SUB_IQA_1����
				w1.show();							//��ת��SUB_IQA����
				//w1.showFullScreen();
				w1.showMaximized();
			}
		});

	//�����޲ο�ͼ����������
	connect(ui.action3, &QAction::triggered, this, &DP::FR_IQA);

	//����˶����ƣ��������Ƶ������
	connect(ui.action1, &QAction::triggered,
		[=] {
			w_c.show();
		});

	//�����źţ������������ļ�·�������������۽���
	connect(this, &DP::send_Pic_Path, &w1, &SUB_IQA_1::Get_Path);

	//�˵����������ź����
	QDesktopServices q;								//���ڿ����������ļ�
	connect(ui.actionBMP, &QAction::triggered,
		[=]{
			QString local_path = QString(filePath + "/Pic/PicBMP");
			QString path = QString("file:///") + local_path;
			//QProcess::startDetached("explorer" + local_path);
			QUrl u(path);
			bool isopen = q.openUrl(u);
		});

	connect(ui.actionJPG, &QAction::triggered,
		[=] {
			QString local_path = QString(filePath + "/Pic/PicJPG");
			QString path = QString("file:///") + local_path;
			//QProcess::startDetached("explorer" + local_path);
			QUrl u(path);
			bool isopen = q.openUrl(u);
		});
	connect(ui.actionip,&QAction::triggered,
		[=] {
			qDebug() << "ss";
		});

	//���߳�
	show_Thread = new Show_Thread;
	thread = new QThread(this);
	show_Thread->moveToThread(thread);
	thread->start();

	
	connect(ui.btn_start_grabing, &QPushButton::clicked, show_Thread, &Show_Thread::show_Pic);
	connect(show_Thread, &Show_Thread::update_Show, this, &DP::get_Image);
	//���ڹرյ�ʱ����Ҫ����һ���Ĳ�������ʹ���������˳�
	connect(this, &QMainWindow::destroyed, this, &DP::deal_Close); 
	connect(this, &QMainWindow::destroyed, this, &DP::on_btn_close_click);
	get_Full_Path();					//��ȡ��ǰ����·��

}
//��õ�ǰӦ�ó����·��
void DP::get_Full_Path() {
	filePath = qApp->applicationDirPath();
	QDir* dir1 = new QDir;
	//dir1->mkdir("F:/C++Space/DP/Debug/Pic");
	qDebug() << filePath;
	if (dir1->exists(filePath + "/Pic/PicJPG") == false) {
		dir1->mkpath(filePath + "/Pic/PicJPG");
	}
	if (dir1->exists(filePath + "/Pic/PicBMP") == false) {
		dir1->mkpath(filePath + "/Pic/PicBMP");
	}
}

//�رմ���ǰ��һЩ����
void DP::deal_Close() {
	show_Thread->set_Flag(true);	//������ǰ�˳���ʱ���������
	thread->quit();
	thread->wait();
	//thread_1->quit();
	//thread_1->wait();
	delete show_Thread;
}

//�ۺ���������Show_Thread�̴߳�������ͼƬ
void DP::get_Image(QImage tempImg) {
	if (tempImg.isNull()) {
		return;
	}
	ui.lbl_show_pic->setPixmap(QPixmap::fromImage(tempImg));
	//update();
}

//��ť�����������
void DP::on_btn_search_click() {
	QString tempInf;
	status = 5;
	deInf = hk_Camera->connectCamera(status);
	ui.lbl_state->setText(QString::fromLocal8Bit("�ҵ��豸"));
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("ö���豸ʧ�ܣ�"));
		return;
	}
	else if(status == 0){
		ui.lbl_state->setText(QString::fromLocal8Bit("�Ҳ����豸��"));
		return;
	}
	for (auto c : deInf) {
		tempInf = QString::fromUtf8(c.c_str());
		ui.cbx_device->addItem(tempInf);
	}
	//��������
	ui.btn_open->setEnabled(true);
	ui.btn_search->setEnabled(false);
}

//��ť�ر��������
void DP::on_btn_close_click() {
	show_Thread->set_Flag(true);
	isStartCamera = true;											//��֤����ڹر�ǰֻ����һ��
	status = hk_Camera->closeCamera();
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("����ر�ʧ�ܣ������룺").append(QString::number(status)));
		return;
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("����ر�"));
	}
	ui.btn_search->setEnabled(true);
	ui.btn_close->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
}

//��ťֹͣ�ɼ�����
void DP::on_btn_end_grabing_click() {
	//�߳��е�ֹͣ����
	show_Thread->set_Flag(true);

	ui.btn_start_grabing->setEnabled(true);
	ui.btn_close->setEnabled(true);
	ui.btn_end_grabing->setEnabled(false);
}

//��ť��ȡ��������
void DP::on_btn_get_param_click() {
	float tmp;
	QString data;
	//��ȡ�ع�
	status = hk_Camera->getExposure(tmp);
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("��ȡ�ع�����ʧ��"));
	}
	else {
		data = QString("%1").arg(tmp);
		ui.let_exposure->setText(data);
	}
	//��ȡ����
	status = hk_Camera->getGain(tmp);
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("��ȡ��������ʧ��"));
	}
	else {
		data = QString("%1").arg(tmp);
		ui.let_exposure->setText(data);
	}
}

//��ť���������
void DP::on_btn_open_click() {
	//int o = std::stoi(ui.cbx_device->currentIndex);
	status = hk_Camera->openCamera(ui.cbx_device->currentIndex());
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("����ʧ�ܣ������룺").append(QString::number(status)));
		return;
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("�豸����"));
	}
	ui.btn_close->setEnabled(true);
	ui.btn_start_grabing->setEnabled(true);
	ui.btn_open->setEnabled(false);
	
}

//��ť����BMPͼƬ����
void DP::on_btn_save_BMP_click() {
	//��Ϣ��---���̻߳�������ת---��߻����һ����ֵ�����---��һ����Ϣ��һ���ǳɹ���
	status = show_Thread->save_BMP();
	if (show_Thread->is_Save()) {
		QMessageBox::information(nullptr, "", QStringLiteral("Sucessed!\nBMP%1.").arg(status));
		return;
	}
	QMessageBox::information(nullptr, "", "Failed");
	
}

//��ť����JPGͼƬ����
void DP::on_btn_save_JPG_click() {
	status = show_Thread->save_JPG();
	if (show_Thread->is_Save()) {
		QMessageBox::information(nullptr, "", QStringLiteral("Sucessed!\nJPG%1.").arg(status));
		return;
	}	
	QMessageBox::information(nullptr, "", "Failed");
	
}

//��ť��ʼ�ɼ�����
void DP::on_btn_start_grabing_click() {
	show_Thread->set_Flag(false);
	//���ֻ��Ҫ����һ�Σ�����Ҫ�ظ��������������һ����־������֤�ڹر����ǰֻ����һ�����
	if (isStartCamera) {
		status = hk_Camera->startCamera();
		if (status != 0) {
			ui.lbl_state->setText(QString::fromLocal8Bit("�ɼ�ʧ�ܣ������룺").append(QString::number(status)));
			return;
		}
		isStartCamera = false;
	}
	ui.lbl_state->setText(QString::fromLocal8Bit("�ɼ��ɹ�"));
	ui.btn_end_grabing->setEnabled(true);
	ui.btn_close->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
	//ui.btn_close->setEnabled(false);
}

//��ť���ò�������
void DP::on_btn_set_param_click() {
	float data;
	data = (ui.let_exposure->text()).toFloat();
	status = hk_Camera->setExposure(data);
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("�����ع�ʧ��"));
	}
	data = (ui.let_gain->text()).toFloat();
	status = hk_Camera->setGain(data);
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("��������ʧ��"));
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("�������óɹ�"));
	}
}

//����Ҷ�ͼƬ����Canny��Ե����ķ���ֵ
double DP::Canny_Evaluate(Mat input) {
	double result;
	Mat result_Mat, mean, stddev;
	Canny(input, result_Mat, 100, 100);//canny��Ե���
	imshow("ss", result_Mat);
	meanStdDev(result_Mat, mean, stddev);
	result = stddev.at<double>(0, 0);
	return pow(result,2);
}

//����Ҷ�ͼƬ����Laplacian��Ե����ĵķ���ֵ
double DP::Lap_Evaluate(Mat input) {
	double result;
	Mat result_Mat, mean, stddev;
	Laplacian(input, result_Mat, CV_16U);
	//cvLaplace(&input, &result_Mat, 3);
	imshow("l",result_Mat);
	imshow("o", input);
	meanStdDev(result_Mat, mean, stddev);
	result = stddev.at<double>(0, 0);
	return pow(result, 2);
}

//����Ҷ�ͼ��ľ�ֵ�뷽��ĺ���
double DP::Mean_Evaluate(Mat input,double &x) {
	double result;
	Mat mean, stddev;
	meanStdDev(input, mean, stddev);
	x = stddev.at<double>(0,0);
	result = mean.at<double>(0, 0);
	return result;
}

//����FR_IQA���ۺ���
void DP::FR_IQA() {
	//���ļ�֮���ȡ�ļ�·��������fileName��
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("open a file."),
		filePath + "/Pic",
		tr("images(*.png *jpg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
	if (fileName.isEmpty() == false) {
		double c_Result, l_Result,m_Result,d_Result;
		//��QStringת��Ϊimread����ʶ���string
		string str = fileName.toStdString();
		str.c_str();
		//����ͼƬ
		Mat input = imread(str);
		Mat gray_Input;

		//���input�ǲ�ɫͼ��תΪ�Ҷ�ͼ�����ǵĻ��Ͳ�������
		if (input.channels() == 3) {
			cvtColor(input, gray_Input, CV_BGR2GRAY);
		}
		else {
			gray_Input.copyTo(input);
		}
		//cvtColor(input, gray_Input, CV_BGR2GRAY);
		//��������
		l_Result = Lap_Evaluate(gray_Input);
		c_Result = Canny_Evaluate(gray_Input);
		m_Result = Mean_Evaluate(gray_Input, d_Result);
		//�жϱ�׼��L(>150),M(70-210),C(>3000)
		QString isBlur, isDark;
		if ((l_Result > 150) && (c_Result > 3000)) {
			isBlur = isBlur.fromLocal8Bit("����");
		}
		else {
			isBlur = isBlur.fromLocal8Bit("ģ��");
		}
		if ((m_Result >= 70) && (m_Result <= 210)) {
			isDark = isDark.fromLocal8Bit("��������\n");
		}
		else if(m_Result > 210 && d_Result < 50){
			isDark = isDark.fromLocal8Bit("����\n");
		}
		else if(m_Result < 70 && d_Result < 50){
			isDark = isDark.fromLocal8Bit("����\n");
		}
		else {
			isDark = isDark.fromLocal8Bit("�ֲ������쳣\n");
		}
		//��ʾ���۽��
		QMessageBox::information(NULL, QString::fromLocal8Bit("�������")
			, QString::fromLocal8Bit("Canny��⣺%1��Lapla��⣺%2��"
				"��ֵ��⣺%3,�����⣺%4\n").arg(c_Result).arg(l_Result)
			.arg(m_Result).arg(d_Result).append(isDark).append(isBlur));
	}
}