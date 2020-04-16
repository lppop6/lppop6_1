#pragma once
#include <QObject>
#include <qimage.h>
#include <qthread.h>
#include <qpainter.h>
#include "qdebug.h"
#include <vector>
#include "Global_Val.h"



class Map_Show_Thread :public QObject
{
	Q_OBJECT
public:
	Map_Show_Thread(QObject* parent = nullptr);
	~Map_Show_Thread();
	void map_update(int, int);								//用于地图更新
	void show_Track(int, int, int, int);					//用于显示轨迹，四个参数分别是本次的坐标点（X，Y）与上一次的坐标点（X_Before，Y_Before）

private:

signals:
	void send_Map(QImage);									//发送信号给control_test,用来更新地图

};


