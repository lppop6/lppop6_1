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

	//��������
	SUB_IQA_1 w1;
	control_test w_c;
	//������Ҫ�Ĳ���
	vector<string> deInf;
	int status ;
	Mat wanted_pic;
	//���߳�
	//����ͼ��ɼ�
	Show_Thread* show_Thread;
	QThread* thread;

	//���ڼ���ͼ�������--NF
	//IQA_NF_Thread iqa_Nf_Thread;

	//QThread* thread_1;
	//����Ƿ���Ҫ�����ı�־��
	bool isStartCamera;
	//NF-IQA
	double Canny_Evaluate(cv::Mat);
	double Lap_Evaluate(cv::Mat);
	double Mean_Evaluate(cv::Mat,double&);

	//���ڻ�ȡ�ļ�·��
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
	//���߳�ʹ�ú���
	void deal_Close();					//��������ƺ�����Ӧ�÷��ڲۺ������
	void get_Image(QImage tempImg);
	void FR_IQA();
signals:
	void send_Pic_Path(QString);		//�������ļ���λ�÷��͸�SUB_IQA���ڵĺ���---�������۴���
	
	void send_Pic_Path_NR(QString);		//���ļ���Σ�����͸�IQA_NF_Thread�߳�---�޲�����
};
