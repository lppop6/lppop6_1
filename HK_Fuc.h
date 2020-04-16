#pragma once
#include <MvCameraControl.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
//#include "Global_Val.h"

using namespace cv;
using namespace std;

//������ɼ��������ϳ�һ����
class HK_Fuc
{
	//����ģʽ---����
public:
	static HK_Fuc* getInstance() {
		return instance;
	}
private:
	HK_Fuc::HK_Fuc() {
		m_hDevHandle = nullptr;
	}
	HK_Fuc::~HK_Fuc() {
		if (m_hDevHandle) {
					MV_CC_DestroyHandle(m_hDevHandle);
					m_hDevHandle = nullptr;
			}
	}
	static HK_Fuc* instance;
public:
	//�������
	vector<string> connectCamera(int& status);  		//�����豸  status�����ж�״̬  ����ֵ���������������Ϣ
	int startCamera();									//��ʼ�ɼ�
	int stopCamera();									//ֹͣ�ɼ�
	int openCamera(int id);								//�����  ͨ��id��ѡ���ĸ������
	int closeCamera();									//�ر����
	int readBuffer(Mat& image);							//��ȡ�������
	int getExposure(float& temp);						//����ع����
	int getGain(float& temp);							//����������
	int setExposure(float currentValue);				//�����ع����
	int setGain(float currentValue);					//�����������
	int saveBMP();										//����BMP
	int saveJPG();										//����JPG

	void delM();										//�����ͷ�ָ��

	//�������
	unsigned int m_nBufSizeForSaveImage;				//���ڱ���ͼ��Ļ���
	unsigned int m_nBufSizeForDriver;					//����������ȡͼ��
	MV_CC_DEVICE_INFO_LIST m_stDevList;					//�豸�Ľṹ������������洢�豸�б�
	MV_CC_DEVICE_INFO* m_Device = nullptr;				//�豸���󣬺�������ͷ�

private:
	void* m_hDevHandle;									//���
	//���ڲɼ�һ֡ͼ����й�ͼ���������
	unsigned char* pDate;								//ͼ������ָ�룬��Ҫ�ͷ�
	unsigned char* m_pBufForSaveImage;					//ת��ͼ������ָ�룬��Ҫ�ͷ�
	unsigned int nRecvBufSize = 0;						//ͼ�����ݲ���
	MVCC_INTVALUE stParam;								//ͼ�����ݲ���---���ڻ�ȡһ֡ͼ��
	MVCC_FLOATVALUE picParam;							//ͼ�����ݲ���---���ڻ�ȡ������ͼ�����
};



