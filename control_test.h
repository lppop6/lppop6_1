#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_control_test.h"
#include <qpainter.h>
#include <qthread.h>
#include "Map_Show_Thread.h"
#include "Global_Val.h"
#include "Control_604.h"
#include "qtimer.h"
#include "ui_control_test.h"

class control_test : public QMainWindow
{
	Q_OBJECT

public:
	control_test(QWidget* parent = Q_NULLPTR);
	Control_604 con604;
private:
	Ui::control_test ui;
	QThread* thread;					
	Map_Show_Thread* map_Thread;		//地图显示的线程
	void map_Close();					//地图关闭函数
	void init_Map();					//初始化地图函数
	//int get_Max_Com_Divisor(int ,int );
	int X_Before;						//用于显示上一次的点X位置
	int Y_Before;						//用于显示上一次的点Y位置

	QTimer* myT;
public slots:
	void update_Map(QImage);			//用于更新图像
	void show_Track();					//用于显示轨迹
	void track_Reset();					//用于重置轨迹点
	void move_Reset();					//复位按钮槽函数
	void move_Start();					//开始运动槽函数
	void set_V();						//设置速度槽函数
	void set_X_Y(int, int);				//设置X，Y坐标槽函数
};

