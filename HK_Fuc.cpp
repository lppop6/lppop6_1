#include "HK_Fuc.h"
#include <qdebug.h>

//单例模式
HK_Fuc* HK_Fuc::instance = new HK_Fuc;//这个不能写在.h文件上，写在.h文件上会出现错误

//HK_Fuc::HK_Fuc() {
//	m_hDevHandle = nullptr;
//}
//
//HK_Fuc::~HK_Fuc() {
//	if (m_hDevHandle) {
//		MV_CC_DestroyHandle(m_hDevHandle);
//		m_hDevHandle = nullptr;
//	}
//}

vector<string> HK_Fuc::connectCamera(int& status) {
	vector<string> deviceInfo;
	int tempValue = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);
	if (tempValue != MV_OK) {
		status = 0;       //枚举设备失败
	}
	if (m_stDevList.nDeviceNum == 0) {
		status = 1;      //找不到设备
	}
	//获得所有设备的型号名字
	//这里不能使用范围for语句，会出现错误
	for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++) {
		MV_CC_DEVICE_INFO* c = m_stDevList.pDeviceInfo[i];
		if (c == nullptr) {
			qDebug() << "错误！";
			continue;
		}
		try
		{
			if (c->nTLayerType == MV_USB_DEVICE) {
				string tempI1 (reinterpret_cast<char*>(c->SpecialInfo.stUsb3VInfo.chSerialNumber));
				deviceInfo.push_back(tempI1);
			}
			else if (c->nTLayerType == MV_GIGE_DEVICE) {
				string tempI2 (reinterpret_cast<char*>(c->SpecialInfo.stGigEInfo.chModelName));
				deviceInfo.push_back(tempI2);
			}
		}
		catch (const std::exception&)
		{
			
		}
	}
	return deviceInfo;
}

int HK_Fuc::openCamera(int id) {
	//创建句柄，打开相机
	//memcpy(m_Device, m_stDevList.pDeviceInfo[id], sizeof(MV_CC_DEVICE_INFO));
	m_Device = m_stDevList.pDeviceInfo[id];
	int TempValue = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
	if (TempValue != 0) {
		return 1;				//创建句柄失败
	}
	TempValue = MV_CC_OpenDevice(m_hDevHandle, MV_ACCESS_Exclusive, 0);
	if (TempValue != 0) {
		return 2;				//开启相机失败
	}
	return 0;
}

//开启相机
int HK_Fuc::startCamera() {
	//qDebug() << "sddd";
	int tempValue = MV_CC_StartGrabbing(m_hDevHandle);
	//qDebug() << "aaaa";
	if (tempValue != 0) {
		return tempValue;				//相机开启采集失败
	}
	return 0;
}

//停止相机
int HK_Fuc::stopCamera() {
	int tempValue = MV_CC_StopGrabbing(m_hDevHandle);
	if (tempValue != 0) {
		return tempValue;				//相机停止失败
	}
	return 0;
}

//关闭相机
int HK_Fuc::closeCamera() {
	if (m_hDevHandle == nullptr) {
		return 0;
	}
	int tempValue = MV_CC_CloseDevice(m_hDevHandle);
	m_hDevHandle = nullptr;
	if (tempValue != 0) {
		return tempValue;				//相机关闭失败
	}
	return 0;
}

//读取相机采集的数据
int HK_Fuc::readBuffer(Mat& image) {
	
    bool isMono;						//用于判断彩色或是黑白
	int tempValue;
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };

	if (nRecvBufSize == 0) {
		memset(&stParam, 0, sizeof(MVCC_INTVALUE));
		tempValue = MV_CC_GetIntValue(m_hDevHandle, "PayloadSize", &stParam);
		if (tempValue != 0)
		{
			return 1;						//获取图像尺寸失败
		}
		nRecvBufSize = stParam.nCurValue;
	}
    //memset(&stParam, 0, sizeof(MVCC_INTVALUE));
    //int tempValue = MV_CC_GetIntValue(m_hDevHandle, "PayloadSize", &stParam);
    //if (tempValue != 0)
    //{
    //    return 1;						//获取图像尺寸失败
    //}
    //nRecvBufSize = stParam.nCurValue;

    //pDate = (unsigned char*)malloc(nRecvBufSize);
	pDate = static_cast<unsigned char*>(malloc(nRecvBufSize));
    tempValue = MV_CC_GetOneFrameTimeout(m_hDevHandle, pDate, nRecvBufSize, &stImageInfo, 700);
    if (tempValue != 0)
    {
        return 2;						//获取一帧图像失败
    }
    m_nBufSizeForSaveImage = stImageInfo.nWidth * stImageInfo.nHeight * 3 + 2048;
    //m_pBufForSaveImage = (unsigned char*)malloc(m_nBufSizeForSaveImage);
	m_pBufForSaveImage = static_cast<unsigned char*>(malloc(m_nBufSizeForSaveImage));
    switch (stImageInfo.enPixelType)
    {
    case PixelType_Gvsp_Mono8:
    case PixelType_Gvsp_Mono10:
    case PixelType_Gvsp_Mono10_Packed:
    case PixelType_Gvsp_Mono12:
    case PixelType_Gvsp_Mono12_Packed:
        isMono = true;
        break;
    default:
        isMono = false;
        break;
    }
    if (isMono)
    {
        image = Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC1, pDate);
    }
    else
    {
        //转换图像格式为BGR8
        MV_CC_PIXEL_CONVERT_PARAM stConvertParam = { 0 };
        memset(&stConvertParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
        stConvertParam.nWidth = stImageInfo.nWidth;                        //ch:图像宽 | en:image width
        stConvertParam.nHeight = stImageInfo.nHeight;                      //ch:图像高 | en:image height
        stConvertParam.pSrcData = pDate;                                   //ch:输入数据缓存 | en:input data buffer
        stConvertParam.nSrcDataLen = stImageInfo.nFrameLen;                //ch:输入数据大小 | en:input data size
        stConvertParam.enSrcPixelType = stImageInfo.enPixelType;           //ch:输入像素格式 | en:input pixel format
        stConvertParam.enDstPixelType = PixelType_Gvsp_BGR8_Packed;        //ch:输出像素格式 | en:output pixel format  适用于OPENCV的图像格式
        stConvertParam.pDstBuffer = m_pBufForSaveImage;                    //ch:输出数据缓存 | en:output data buffer
        stConvertParam.nDstBufferSize = m_nBufSizeForSaveImage;            //ch:输出缓存大小 | en:output buffer size
        MV_CC_ConvertPixelType(m_hDevHandle, &stConvertParam);
        image = Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC3, m_pBufForSaveImage);
    }
    //delete pDate;							//
    //delete m_pBufForSaveImage;				//是否应该在这里释放？
    return 0;
}

//获得曝光时间
int HK_Fuc::getExposure(float& temp) {
	int tempValue = MV_CC_GetFloatValue(m_hDevHandle, "ExposureTime", &picParam);
	if (tempValue != 0) {
		return 1;				//获得曝光时间失败
	}
	temp = picParam.fCurValue;
	return 0;
}

//获得增益
int HK_Fuc::getGain(float& temp) {
	int tempValue = MV_CC_GetFloatValue(m_hDevHandle, "Gain", &picParam);
	if (tempValue != 0) {
		return 1;				//获取增益失败
	}
	temp = picParam.fCurValue;
	return 0;
}

//设置曝光时间
int HK_Fuc::setExposure(float currentValue) {
	int tempValue = MV_CC_SetFloatValue(m_hDevHandle, "ExposureTime", currentValue);
	if (tempValue != 0) {
		return 1;				//设置曝光失败
	}
	return 0;
}

//设置增益
int HK_Fuc::setGain(float currentValue) {
	int tempValue = MV_CC_SetFloatValue(m_hDevHandle, "Gain", currentValue);
	if (tempValue != 0) {
		return 1;				//设置增益失败
	}
	return 0;
}

//delete指针
void HK_Fuc::delM() {
	delete pDate;
	pDate = nullptr;
	delete m_pBufForSaveImage;
	m_pBufForSaveImage = nullptr;
}