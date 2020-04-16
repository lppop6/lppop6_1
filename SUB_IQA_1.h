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
	cv::Mat imageSharpen;							//��˹�񻯺��ͼ��
	cv::Mat imageObscure;							//��˹ģ�����ͼ��
	cv::Mat imageInput;								//ԭͼ��
	//ͼ������
	cv::Mat Gussi_Sharpen(cv::Mat);					//��˹��
	cv::Mat Gussi_Obscure(cv::Mat);					//��˹ģ��
	QImage Mat_to_Qimage(cv::Mat);					//Matת��ΪQImage
	SUB_IQA_2 w2;									//���۲����ĵڶ�������
public slots:
	void Get_Path(QString);							//���������ڴ�����Path
signals:
	void send_Pic_IQA_1(QImage);					//����ԭͼ���ڶ����������۵Ĵ���
};

