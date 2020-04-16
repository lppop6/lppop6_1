#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DP.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <MvCameraControl.h>
#include <vector>
#include <qthread.h>
#include "Show_Thread.h"
#include <qimage.h>
#include "HK_Fuc.h"
#include <qdebug.h>
#include "qdesktopservices.h"
#include "qprocess.h"
#include "qurl.h"
#include "qfiledialog.h"
#include "SUB_IQA_1.h"
//#include "Global_Val.h"
//#include "IQA_NF_Thread.h"
#include <cmath>
#include "control_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>


class DP : public QMainWindow
{
	Q_OBJECT

public:
	DP(QWidget *parent = Q_NULLPTR);

	HK_Fuc* hk_Camera = HK_Fuc::getInstance();
private:
	Ui::DPClass ui;

	//其他界面
	SUB_IQA_1 w1;
	control_test w_c;
	//函数需要的参数
	vector<string> deInf;
	int status ;
	Mat wanted_pic;
	//多线程
	//用于图像采集
	Show_Thread* show_Thread;
	QThread* thread;

	//用于计算图像的质量--NF
	//IQA_NF_Thread iqa_Nf_Thread;

	//QThread* thread_1;
	//相机是否需要开启的标志符
	bool isStartCamera;
	//NF-IQA
	double Canny_Evaluate(cv::Mat);
	double Lap_Evaluate(cv::Mat);
	double Mean_Evaluate(cv::Mat,double&);

	//用于获取文件路径
	void get_Full_Path();
public slots:
	void on_btn_search_click();
	void on_btn_save_BMP_click();
	void on_btn_save_JPG_click();
	void on_btn_get_param_click();
	void on_btn_set_param_click();
	void on_btn_open_click();
	void on_btn_close_click();
	void on_btn_end_grabing_click();
	void on_btn_start_grabing_click();
	//多线程使用函数
	void deal_Close();					//这个函数似乎并不应该放在槽函数这边
	void get_Image(QImage tempImg);
	void FR_IQA();
signals:
	void send_Pic_Path(QString);		//用来将文件的位置发送给SUB_IQA窗口的函数---主观评价窗口
	
	void send_Pic_Path_NR(QString);		//将文件的危机发送给IQA_NF_Thread线程---无参评价
};
