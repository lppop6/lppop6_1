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
	Map_Show_Thread* map_Thread;		//��ͼ��ʾ���߳�
	void map_Close();					//��ͼ�رպ���
	void init_Map();					//��ʼ����ͼ����
	//int get_Max_Com_Divisor(int ,int );
	int X_Before;						//������ʾ��һ�εĵ�Xλ��
	int Y_Before;						//������ʾ��һ�εĵ�Yλ��

	QTimer* myT;
public slots:
	void update_Map(QImage);			//���ڸ���ͼ��
	void show_Track();					//������ʾ�켣
	void track_Reset();					//�������ù켣��
	void move_Reset();					//��λ��ť�ۺ���
	void move_Start();					//��ʼ�˶��ۺ���
	void set_V();						//�����ٶȲۺ���
	void set_X_Y(int, int);				//����X��Y����ۺ���
};

