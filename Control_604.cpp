#include "Control_604.h"

Control_604::Control_604() {

}

Control_604::~Control_604() {
	
}

//����ĳ�ʼ��
void Control_604::Init() {
	ret = smc_board_init(ConnectNo, type, pconnectstring, baud);		//��ʼ�����������ӿ�����
	ret = smc_set_pulse_outmode(ConnectNo, axis, outmode);				//�����������ģʽ
	ret = smc_set_equiv(ConnectNo, axis, equiv);						//�������嵱��ֵ
	ret = smc_set_backlash_unit(ConnectNo, axis, backlash);				//���÷����϶
}

//��ȡ��ǰ�˶�����Ծ���
int Control_604::Get_S() {
	return 0;
}

//��ȡ��ǰ�ٶ�
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

//��ʼ�˶�
void Control_604::Move(double x, double y) {
	AxisArray[0] = 0;													//����岹��0ΪX��
	AxisArray[1] = 1;													//����岹��1ΪY��
	Dist[0] = x;														//����x���˶�����
	Dist[1] = y;														//����Y����˶�����
	//�岹�ٶȲ�������
	ret = smc_set_vector_profile_unit(ConnectNo, myCrd, min_Vel, max_Vel, myTacc, myTdec, stop_Vel);
	//�岹�˶�ƽ������
	ret = smc_set_vector_s_profile(ConnectNo, myCrd, sMode, sPara);
	//��ʼ�˶�
	ret = smc_line_unit(ConnectNo, myCrd, axixsNum, AxisArray, Dist, posi_mode);
}

//��λ
void Control_604::Reset() {
	//��ʼ�ٶ�1000uint������ٶ�1000uint������ʱ��0.1s,ԭ��͵�ƽ��Ч���˲�ʱ��Ϊ0����ԭ�㷽��Ϊ����
	//��ԭ��Ϊһ�λ�ԭ��ģʽ�����������
	//���û�ԭ���ƽ����
	ret = smc_set_home_pin_logic(ConnectNo, 0, 0, 0);//X
	ret = smc_set_home_pin_logic(ConnectNo, 1, 0, 0);//Y
	//���û�ԭ��ģʽ
	ret = smc_set_homemode(ConnectNo, 0, 1, 1, 0, 0);//X
	ret = smc_set_homemode(ConnectNo, 1, 1, 1, 0, 0);//Y
	//���û�ԭ����ɺ�ļ���λ��ֵ
	ret = smc_set_home_position_unit(ConnectNo, 0, 0, 100);
	ret = smc_set_home_position_unit(ConnectNo, 1, 0, 100);
	//���û�ԭ���˶��ٶȲ���
	ret = smc_set_home_profile_unit(ConnectNo, 0, 3000, 3000, 0.1, 0);
	ret = smc_set_home_profile_unit(ConnectNo, 1, 3000, 3000, 0.1, 0);
	//������ԭ��
	ret = smc_home_move(ConnectNo, 0);
	ret = smc_home_move(ConnectNo, 1);

}

//���ò岹����ٶ�
void Control_604::Set_V(double& v) {
	max_Vel = v;//���ò岹�˶�������ٶ�
}

//�رյ��
void Control_604::Close_604() {
	ret = smc_stop(0, 0, 0);
	Reset();
	ret = smc_board_close(ConnectNo);
}