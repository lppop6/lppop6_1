#pragma once
#include "LTSMC.h"
#include <cmath>

//���˶����Ƶĺ������ϳ�һ����
class Control_604
{
public:
	Control_604();
	~Control_604();

	void Init();									//��ʼ������
	void Move(double, double);						//�ƶ���ֱ�߲岹����
	void Reset();									//��λ
	int Get_V();									//��õ�ǰ�ٶ�
	int Get_S();									//������λ��
	void Close_604();								//�رտ�����
	void Set_V(double&);							//���������ٶ�
private:
	short ret;										//���շ���ֵ
	WORD ConnectNo = 0;								//���Ӻ�
	WORD type = 2;									//type�������ͣ�1-���ڣ�2-����
	char* pconnectstring = "192.168.5.11";			//������ip
	DWORD baud = 115200;							//������
	WORD axis = 0;									//�˶���
	WORD outmode = 0;								//�������ģʽ	
	double equiv = 10;								//���嵱��
	double backlash = 10;							//�����϶
	WORD posi_mode = 0;								//0-���ģʽ  1-����ģʽ
	double read_pos;								//��ȡָ�����������ֵ
	WORD AxisArray[2];								//������
	double min_Vel = 0;								//��ʼ�ٶ�Ϊ0
	double max_Vel = 3000;							//����ٶ�Ϊ3000unit
	double myTacc = 0.2;							//�岹�˶��ļ���ʱ��
	double myTdec = 0.1;							//�岹�˶��ļ���ʱ��
	double stop_Vel = 0;							//�岹�˶���ֹͣ�ٶ�
	WORD sMode = 0;									//�����������̶�ֵΪ0
	double sPara = 0.5;								//ƽ��ʱ��Ϊ0.05
	WORD axixsNum = 2;								//�岹�˶�����
	double Dist[2];									//����X��Y���˶�����
	WORD myCrd = 0;									//�岹������ϵ
};


