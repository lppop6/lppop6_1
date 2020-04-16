#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SUB_IQA_1.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Global_Val.h"
#include "qstring.h"
#include "SUB_IQA_2.h"


class SUB_IQA_1: public QMainWindow
{
	Q_OBJECT
public:
	SUB_IQA_1(QWidget *parent = Q_NULLPTR);
private:
	Ui::MainWindow1 ui;
	cv::Mat imageSharpen;							//高斯锐化后的图像
	cv::Mat imageObscure;							//高斯模糊后的图像
	cv::Mat imageInput;								//原图像
	//图像处理函数
	cv::Mat Gussi_Sharpen(cv::Mat);					//高斯锐化
	cv::Mat Gussi_Obscure(cv::Mat);					//高斯模糊
	QImage Mat_to_Qimage(cv::Mat);					//Mat转换为QImage
	SUB_IQA_2 w2;									//主观测评的第二个窗口
public slots:
	void Get_Path(QString);							//接收主窗口传来的Path
signals:
	void send_Pic_IQA_1(QImage);					//发送原图给第二个主观评价的窗口
};

