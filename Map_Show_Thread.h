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
	void map_update(int, int);								//���ڵ�ͼ����
	void show_Track(int, int, int, int);					//������ʾ�켣���ĸ������ֱ��Ǳ��ε�����㣨X��Y������һ�ε�����㣨X_Before��Y_Before��

private:

signals:
	void send_Map(QImage);									//�����źŸ�control_test,�������µ�ͼ

};


