#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SUB_IQA_2.h"
#include "Global_Val.h"
#include "qmessagebox.h"

class SUB_IQA_2:public QMainWindow
{
	Q_OBJECT
public:
	SUB_IQA_2(QWidget* parent = Q_NULLPTR);
	double evaluate();							//�������۷�ֵ
private:
	Ui::MainWindow ui;
public slots:
	void get_Pic_IQA(QImage);					//���IQA�ĵ�ͼ
	void get_Result();							//������۽��

};

