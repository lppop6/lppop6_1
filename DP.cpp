#include "DP.h"

using namespace cv;
extern QString fileNameIQA;		//用于传递到底是哪个文件进行IQA

DP::DP(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//设置初始分裂器的值
	ui.splitter->setStretchFactor(0, 5);
	ui.splitter->setStretchFactor(1, 1);
	//设置最开始除了连接设备外的所有操作相机的按键全为enable
	ui.btn_close->setEnabled(false);
	ui.btn_end_grabing->setEnabled(false);
	ui.btn_open->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
	//初始化保证相机只开启一次的标志符,当相机关闭的时候再将其置位true
	isStartCamera = true;
	//按键的信号与槽
	connect(ui.btn_search, &QPushButton::clicked, this, &DP::on_btn_search_click);
	connect(ui.btn_close, &QPushButton::clicked, this, &DP::on_btn_close_click);
	connect(ui.btn_get_param, &QPushButton::clicked, this, &DP::on_btn_get_param_click);
	connect(ui.btn_end_grabing, &QPushButton::clicked, this, &DP::on_btn_end_grabing_click);
	connect(ui.btn_open, &QPushButton::clicked, this, &DP::on_btn_open_click);
	connect(ui.btn_save_BMP, &QPushButton::clicked, this, &DP::on_btn_save_BMP_click);
	connect(ui.btn_save_JPG, &QPushButton::clicked, this, &DP::on_btn_save_JPG_click);
	connect(ui.btn_set_param, &QPushButton::clicked, this, &DP::on_btn_set_param_click);
	connect(ui.btn_start_grabing, &QPushButton::clicked, this, &DP::on_btn_start_grabing_click);

	//点击菜单中的主观评价，然后可以选择评价某一个文件
	connect(ui.action2, &QAction::triggered,
		[=] {
			QString fileName = QFileDialog::getOpenFileName(
				this,
				tr("open a file."),
				filePath + "/Pic",
				tr("images(*.png *jpg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
			if (fileName.isEmpty() == false) {
				emit send_Pic_Path(fileName);		//发送信号传输文件给SUB_IQA_1窗口
				w1.show();							//跳转到SUB_IQA界面
				//w1.showFullScreen();
				w1.showMaximized();
			}
		});

	//连接无参考图像质量评价
	connect(ui.action3, &QAction::triggered, this, &DP::FR_IQA);

	//点击运动控制，跳出控制电机界面
	connect(ui.action1, &QAction::triggered,
		[=] {
			w_c.show();
		});

	//发送信号（附带待评价文件路径）给主观评价界面
	connect(this, &DP::send_Pic_Path, &w1, &SUB_IQA_1::Get_Path);

	//菜单栏按键的信号与槽
	QDesktopServices q;								//用于开启电脑内文件
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

	//多线程
	show_Thread = new Show_Thread;
	thread = new QThread(this);
	show_Thread->moveToThread(thread);
	thread->start();

	
	connect(ui.btn_start_grabing, &QPushButton::clicked, show_Thread, &Show_Thread::show_Pic);
	connect(show_Thread, &Show_Thread::update_Show, this, &DP::get_Image);
	//窗口关闭的时候需要进行一定的操作才能使程序正常退出
	connect(this, &QMainWindow::destroyed, this, &DP::deal_Close); 
	connect(this, &QMainWindow::destroyed, this, &DP::on_btn_close_click);
	get_Full_Path();					//获取当前程序路径

}
//获得当前应用程序的路径
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

//关闭窗口前的一些处理
void DP::deal_Close() {
	show_Thread->set_Flag(true);	//避免提前退出的时候产生错误
	thread->quit();
	thread->wait();
	//thread_1->quit();
	//thread_1->wait();
	delete show_Thread;
}

//槽函数，接收Show_Thread线程传过来的图片
void DP::get_Image(QImage tempImg) {
	if (tempImg.isNull()) {
		return;
	}
	ui.lbl_show_pic->setPixmap(QPixmap::fromImage(tempImg));
	//update();
}

//按钮搜索相机函数
void DP::on_btn_search_click() {
	QString tempInf;
	status = 5;
	deInf = hk_Camera->connectCamera(status);
	ui.lbl_state->setText(QString::fromLocal8Bit("找到设备"));
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("枚举设备失败！"));
		return;
	}
	else if(status == 0){
		ui.lbl_state->setText(QString::fromLocal8Bit("找不到设备！"));
		return;
	}
	for (auto c : deInf) {
		tempInf = QString::fromUtf8(c.c_str());
		ui.cbx_device->addItem(tempInf);
	}
	//按键操作
	ui.btn_open->setEnabled(true);
	ui.btn_search->setEnabled(false);
}

//按钮关闭相机函数
void DP::on_btn_close_click() {
	show_Thread->set_Flag(true);
	isStartCamera = true;											//保证相机在关闭前只开启一次
	status = hk_Camera->closeCamera();
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("相机关闭失败，错误码：").append(QString::number(status)));
		return;
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("相机关闭"));
	}
	ui.btn_search->setEnabled(true);
	ui.btn_close->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
}

//按钮停止采集函数
void DP::on_btn_end_grabing_click() {
	//线程中的停止函数
	show_Thread->set_Flag(true);

	ui.btn_start_grabing->setEnabled(true);
	ui.btn_close->setEnabled(true);
	ui.btn_end_grabing->setEnabled(false);
}

//按钮获取参数函数
void DP::on_btn_get_param_click() {
	float tmp;
	QString data;
	//获取曝光
	status = hk_Camera->getExposure(tmp);
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("获取曝光数据失败"));
	}
	else {
		data = QString("%1").arg(tmp);
		ui.let_exposure->setText(data);
	}
	//获取增益
	status = hk_Camera->getGain(tmp);
	if (status == 1) {
		ui.lbl_state->setText(QString::fromLocal8Bit("获取增益数据失败"));
	}
	else {
		data = QString("%1").arg(tmp);
		ui.let_exposure->setText(data);
	}
}

//按钮打开相机函数
void DP::on_btn_open_click() {
	//int o = std::stoi(ui.cbx_device->currentIndex);
	status = hk_Camera->openCamera(ui.cbx_device->currentIndex());
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("开启失败，错误码：").append(QString::number(status)));
		return;
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("设备开启"));
	}
	ui.btn_close->setEnabled(true);
	ui.btn_start_grabing->setEnabled(true);
	ui.btn_open->setEnabled(false);
	
}

//按钮保存BMP图片函数
void DP::on_btn_save_BMP_click() {
	//消息框---主线程会首先运转---这边会产生一个奇怪的现象---第一个消息框一定是成功的
	status = show_Thread->save_BMP();
	if (show_Thread->is_Save()) {
		QMessageBox::information(nullptr, "", QStringLiteral("Sucessed!\nBMP%1.").arg(status));
		return;
	}
	QMessageBox::information(nullptr, "", "Failed");
	
}

//按钮保存JPG图片函数
void DP::on_btn_save_JPG_click() {
	status = show_Thread->save_JPG();
	if (show_Thread->is_Save()) {
		QMessageBox::information(nullptr, "", QStringLiteral("Sucessed!\nJPG%1.").arg(status));
		return;
	}	
	QMessageBox::information(nullptr, "", "Failed");
	
}

//按钮开始采集函数
void DP::on_btn_start_grabing_click() {
	show_Thread->set_Flag(false);
	//相机只需要开启一次，不需要重复开启，因此引入一个标志符来保证在关闭相机前只开启一次相机
	if (isStartCamera) {
		status = hk_Camera->startCamera();
		if (status != 0) {
			ui.lbl_state->setText(QString::fromLocal8Bit("采集失败，错误码：").append(QString::number(status)));
			return;
		}
		isStartCamera = false;
	}
	ui.lbl_state->setText(QString::fromLocal8Bit("采集成功"));
	ui.btn_end_grabing->setEnabled(true);
	ui.btn_close->setEnabled(false);
	ui.btn_start_grabing->setEnabled(false);
	//ui.btn_close->setEnabled(false);
}

//按钮设置参数函数
void DP::on_btn_set_param_click() {
	float data;
	data = (ui.let_exposure->text()).toFloat();
	status = hk_Camera->setExposure(data);
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("设置曝光失败"));
	}
	data = (ui.let_gain->text()).toFloat();
	status = hk_Camera->setGain(data);
	if (status != 0) {
		ui.lbl_state->setText(QString::fromLocal8Bit("设置增益失败"));
	}
	else {
		ui.lbl_state->setText(QString::fromLocal8Bit("参数设置成功"));
	}
}

//计算灰度图片经过Canny边缘检测后的方差值
double DP::Canny_Evaluate(Mat input) {
	double result;
	Mat result_Mat, mean, stddev;
	Canny(input, result_Mat, 100, 100);//canny边缘检测
	imshow("ss", result_Mat);
	meanStdDev(result_Mat, mean, stddev);
	result = stddev.at<double>(0, 0);
	return pow(result,2);
}

//计算灰度图片经过Laplacian边缘检测后的的方差值
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

//计算灰度图像的均值与方差的函数
double DP::Mean_Evaluate(Mat input,double &x) {
	double result;
	Mat mean, stddev;
	meanStdDev(input, mean, stddev);
	x = stddev.at<double>(0,0);
	result = mean.at<double>(0, 0);
	return result;
}

//进行FR_IQA检测槽函数
void DP::FR_IQA() {
	//打开文件之后获取文件路径，存在fileName中
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("open a file."),
		filePath + "/Pic",
		tr("images(*.png *jpg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
	if (fileName.isEmpty() == false) {
		double c_Result, l_Result,m_Result,d_Result;
		//将QString转化为imread可以识别的string
		string str = fileName.toStdString();
		str.c_str();
		//加载图片
		Mat input = imread(str);
		Mat gray_Input;

		//如果input是彩色图则转为灰度图，不是的话就不做处理
		if (input.channels() == 3) {
			cvtColor(input, gray_Input, CV_BGR2GRAY);
		}
		else {
			gray_Input.copyTo(input);
		}
		//cvtColor(input, gray_Input, CV_BGR2GRAY);
		//进行评价
		l_Result = Lap_Evaluate(gray_Input);
		c_Result = Canny_Evaluate(gray_Input);
		m_Result = Mean_Evaluate(gray_Input, d_Result);
		//判断标准，L(>150),M(70-210),C(>3000)
		QString isBlur, isDark;
		if ((l_Result > 150) && (c_Result > 3000)) {
			isBlur = isBlur.fromLocal8Bit("清晰");
		}
		else {
			isBlur = isBlur.fromLocal8Bit("模糊");
		}
		if ((m_Result >= 70) && (m_Result <= 210)) {
			isDark = isDark.fromLocal8Bit("亮度正常\n");
		}
		else if(m_Result > 210 && d_Result < 50){
			isDark = isDark.fromLocal8Bit("过亮\n");
		}
		else if(m_Result < 70 && d_Result < 50){
			isDark = isDark.fromLocal8Bit("过暗\n");
		}
		else {
			isDark = isDark.fromLocal8Bit("局部亮度异常\n");
		}
		//显示评价结果
		QMessageBox::information(NULL, QString::fromLocal8Bit("分析结果")
			, QString::fromLocal8Bit("Canny检测：%1，Lapla检测：%2，"
				"均值检测：%3,方差检测：%4\n").arg(c_Result).arg(l_Result)
			.arg(m_Result).arg(d_Result).append(isDark).append(isBlur));
	}
}