#pragma once
#include <MvCameraControl.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
//#include "Global_Val.h"

using namespace cv;
using namespace std;

//将相机采集函数集合成一个库
class HK_Fuc
{
	//单例模式---饿汉
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
	//相机函数
	vector<string> connectCamera(int& status);  		//连接设备  status用来判断状态  返回值用来返回相机的信息
	int startCamera();									//开始采集
	int stopCamera();									//停止采集
	int openCamera(int id);								//打开相机  通过id来选择哪个相机打开
	int closeCamera();									//关闭相机
	int readBuffer(Mat& image);							//读取相机缓存
	int getExposure(float& temp);						//获得曝光参数
	int getGain(float& temp);							//获得增益参数
	int setExposure(float currentValue);				//设置曝光参数
	int setGain(float currentValue);					//设置增益参数
	int saveBMP();										//保存BMP
	int saveJPG();										//保存JPG

	void delM();										//用于释放指针

	//相机参数
	unsigned int m_nBufSizeForSaveImage;				//用于保存图像的缓存
	unsigned int m_nBufSizeForDriver;					//用于驱动获取图像
	MV_CC_DEVICE_INFO_LIST m_stDevList;					//设备的结构体变量，用来存储设备列表
	MV_CC_DEVICE_INFO* m_Device = nullptr;				//设备对象，后面必须释放

private:
	void* m_hDevHandle;									//句柄
	//用于采集一帧图像和有关图像参数操作
	unsigned char* pDate;								//图像数据指针，需要释放
	unsigned char* m_pBufForSaveImage;					//转换图像数据指针，需要释放
	unsigned int nRecvBufSize = 0;						//图像数据参数
	MVCC_INTVALUE stParam;								//图像数据参数---用于获取一帧图像
	MVCC_FLOATVALUE picParam;							//图像数据参数---用于获取和设置图像参数
};



