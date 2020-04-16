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
	double evaluate();							//计算评价分值
private:
	Ui::MainWindow ui;
public slots:
	void get_Pic_IQA(QImage);					//获得IQA的地图
	void get_Result();							//获得评价结果

};

