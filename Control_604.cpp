#include "Control_604.h"

Control_604::Control_604() {

}

Control_604::~Control_604() {
	
}

//电机的初始化
void Control_604::Init() {
	ret = smc_board_init(ConnectNo, type, pconnectstring, baud);		//初始化，网口连接控制器
	ret = smc_set_pulse_outmode(ConnectNo, axis, outmode);				//设置脉冲输出模式
	ret = smc_set_equiv(ConnectNo, axis, equiv);						//设置脉冲当量值
	ret = smc_set_backlash_unit(ConnectNo, axis, backlash);				//设置反向间隙
}

//获取当前运动的相对距离
int Control_604::Get_S() {
	return 0;
}

//获取当前速度
int Control_604::Get_V() {
	double x;
	double y;
	double result;
	smc_read_current_speed_unit(ConnectNo, 0, &x);
	smc_read_current_speed_unit(ConnectNo, 1, &y);
	result = pow(x, 2) + pow(y, 2);
	result = sqrt(result);
	return result;
}

//开始运动
void Control_604::Move(double x, double y) {
	AxisArray[0] = 0;													//定义插补轴0为X轴
	AxisArray[1] = 1;													//定义插补轴1为Y轴
	Dist[0] = x;														//定义x轴运动距离
	Dist[1] = y;														//定义Y轴的运动距离
	//插补速度参数设置
	ret = smc_set_vector_profile_unit(ConnectNo, myCrd, min_Vel, max_Vel, myTacc, myTdec, stop_Vel);
	//插补运动平滑参数
	ret = smc_set_vector_s_profile(ConnectNo, myCrd, sMode, sPara);
	//开始运动
	ret = smc_line_unit(ConnectNo, myCrd, axixsNum, AxisArray, Dist, posi_mode);
}

//复位
void Control_604::Reset() {
	//初始速度1000uint，最大速度1000uint，加速时间0.1s,原点低电平有效，滤波时间为0，回原点方向为正向，
	//回原点为一次回原点模式，脉冲计数，
	//设置回原点电平参数
	ret = smc_set_home_pin_logic(ConnectNo, 0, 0, 0);//X
	ret = smc_set_home_pin_logic(ConnectNo, 1, 0, 0);//Y
	//设置回原点模式
	ret = smc_set_homemode(ConnectNo, 0, 1, 1, 0, 0);//X
	ret = smc_set_homemode(ConnectNo, 1, 1, 1, 0, 0);//Y
	//设置回原点完成后的计数位置值
	ret = smc_set_home_position_unit(ConnectNo, 0, 0, 100);
	ret = smc_set_home_position_unit(ConnectNo, 1, 0, 100);
	//设置回原点运动速度参数
	ret = smc_set_home_profile_unit(ConnectNo, 0, 3000, 3000, 0.1, 0);
	ret = smc_set_home_profile_unit(ConnectNo, 1, 3000, 3000, 0.1, 0);
	//启动回原点
	ret = smc_home_move(ConnectNo, 0);
	ret = smc_home_move(ConnectNo, 1);

}

//设置插补最大速度
void Control_604::Set_V(double& v) {
	max_Vel = v;//设置插补运动的最大速度
}

//关闭电机
void Control_604::Close_604() {
	ret = smc_stop(0, 0, 0);
	Reset();
	ret = smc_board_close(ConnectNo);
}