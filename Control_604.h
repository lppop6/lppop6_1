#pragma once
#include "LTSMC.h"
#include <cmath>

//将运动控制的函数集合成一个库
class Control_604
{
public:
	Control_604();
	~Control_604();

	void Init();									//初始化函数
	void Move(double, double);						//移动，直线插补函数
	void Reset();									//复位
	int Get_V();									//获得当前速度
	int Get_S();									//获得相对位移
	void Close_604();								//关闭控制器
	void Set_V(double&);							//在线设置速度
private:
	short ret;										//接收返回值
	WORD ConnectNo = 0;								//连接号
	WORD type = 2;									//type连接类型，1-串口，2-网口
	char* pconnectstring = "192.168.5.11";			//控制器ip
	DWORD baud = 115200;							//波特率
	WORD axis = 0;									//运动轴
	WORD outmode = 0;								//脉冲输出模式	
	double equiv = 10;								//脉冲当量
	double backlash = 10;							//反向间隙
	WORD posi_mode = 0;								//0-相对模式  1-绝对模式
	double read_pos;								//读取指令脉冲计数器值
	WORD AxisArray[2];								//定义轴
	double min_Vel = 0;								//起始速度为0
	double max_Vel = 3000;							//最大速度为3000unit
	double myTacc = 0.2;							//插补运动的加速时间
	double myTdec = 0.1;							//插补运动的减速时间
	double stop_Vel = 0;							//插补运动的停止速度
	WORD sMode = 0;									//保留参数，固定值为0
	double sPara = 0.5;								//平滑时间为0.05
	WORD axixsNum = 2;								//插补运动轴数
	double Dist[2];									//定义X、Y轴运动距离
	WORD myCrd = 0;									//插补的坐标系
};


