#include "HK_Fuc.h"
#include <qdebug.h>

//����ģʽ
HK_Fuc* HK_Fuc::instance = new HK_Fuc;//�������д��.h�ļ��ϣ�д��.h�ļ��ϻ���ִ���

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
		status = 0;       //ö���豸ʧ��
	}
	if (m_stDevList.nDeviceNum == 0) {
		status = 1;      //�Ҳ����豸
	}
	//��������豸���ͺ�����
	//���ﲻ��ʹ�÷�Χfor��䣬����ִ���
	for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++) {
		MV_CC_DEVICE_INFO* c = m_stDevList.pDeviceInfo[i];
		if (c == nullptr) {
			qDebug() << "����";
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
	//��������������
	//memcpy(m_Device, m_stDevList.pDeviceInfo[id], sizeof(MV_CC_DEVICE_INFO));
	m_Device = m_stDevList.pDeviceInfo[id];
	int TempValue = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
	if (TempValue != 0) {
		return 1;				//�������ʧ��
	}
	TempValue = MV_CC_OpenDevice(m_hDevHandle, MV_ACCESS_Exclusive, 0);
	if (TempValue != 0) {
		return 2;				//�������ʧ��
	}
	return 0;
}

//�������
int HK_Fuc::startCamera() {
	//qDebug() << "sddd";
	int tempValue = MV_CC_StartGrabbing(m_hDevHandle);
	//qDebug() << "aaaa";
	if (tempValue != 0) {
		return tempValue;				//��������ɼ�ʧ��
	}
	return 0;
}

//ֹͣ���
int HK_Fuc::stopCamera() {
	int tempValue = MV_CC_StopGrabbing(m_hDevHandle);
	if (tempValue != 0) {
		return tempValue;				//���ֹͣʧ��
	}
	return 0;
}

//�ر����
int HK_Fuc::closeCamera() {
	if (m_hDevHandle == nullptr) {
		return 0;
	}
	int tempValue = MV_CC_CloseDevice(m_hDevHandle);
	m_hDevHandle = nullptr;
	if (tempValue != 0) {
		return tempValue;				//����ر�ʧ��
	}
	return 0;
}

//��ȡ����ɼ�������
int HK_Fuc::readBuffer(Mat& image) {
	
    bool isMono;						//�����жϲ�ɫ���Ǻڰ�
	int tempValue;
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };

	if (nRecvBufSize == 0) {
		memset(&stParam, 0, sizeof(MVCC_INTVALUE));
		tempValue = MV_CC_GetIntValue(m_hDevHandle, "PayloadSize", &stParam);
		if (tempValue != 0)
		{
			return 1;						//��ȡͼ��ߴ�ʧ��
		}
		nRecvBufSize = stParam.nCurValue;
	}
    //memset(&stParam, 0, sizeof(MVCC_INTVALUE));
    //int tempValue = MV_CC_GetIntValue(m_hDevHandle, "PayloadSize", &stParam);
    //if (tempValue != 0)
    //{
    //    return 1;						//��ȡͼ��ߴ�ʧ��
    //}
    //nRecvBufSize = stParam.nCurValue;

    //pDate = (unsigned char*)malloc(nRecvBufSize);
	pDate = static_cast<unsigned char*>(malloc(nRecvBufSize));
    tempValue = MV_CC_GetOneFrameTimeout(m_hDevHandle, pDate, nRecvBufSize, &stImageInfo, 700);
    if (tempValue != 0)
    {
        return 2;						//��ȡһ֡ͼ��ʧ��
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
        //ת��ͼ���ʽΪBGR8
        MV_CC_PIXEL_CONVERT_PARAM stConvertParam = { 0 };
        memset(&stConvertParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
        stConvertParam.nWidth = stImageInfo.nWidth;                        //ch:ͼ��� | en:image width
        stConvertParam.nHeight = stImageInfo.nHeight;                      //ch:ͼ��� | en:image height
        stConvertParam.pSrcData = pDate;                                   //ch:�������ݻ��� | en:input data buffer
        stConvertParam.nSrcDataLen = stImageInfo.nFrameLen;                //ch:�������ݴ�С | en:input data size
        stConvertParam.enSrcPixelType = stImageInfo.enPixelType;           //ch:�������ظ�ʽ | en:input pixel format
        stConvertParam.enDstPixelType = PixelType_Gvsp_BGR8_Packed;        //ch:������ظ�ʽ | en:output pixel format  ������OPENCV��ͼ���ʽ
        stConvertParam.pDstBuffer = m_pBufForSaveImage;                    //ch:������ݻ��� | en:output data buffer
        stConvertParam.nDstBufferSize = m_nBufSizeForSaveImage;            //ch:��������С | en:output buffer size
        MV_CC_ConvertPixelType(m_hDevHandle, &stConvertParam);
        image = Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC3, m_pBufForSaveImage);
    }
    //delete pDate;							//
    //delete m_pBufForSaveImage;				//�Ƿ�Ӧ���������ͷţ�
    return 0;
}

//����ع�ʱ��
int HK_Fuc::getExposure(float& temp) {
	int tempValue = MV_CC_GetFloatValue(m_hDevHandle, "ExposureTime", &picParam);
	if (tempValue != 0) {
		return 1;				//����ع�ʱ��ʧ��
	}
	temp = picParam.fCurValue;
	return 0;
}

//�������
int HK_Fuc::getGain(float& temp) {
	int tempValue = MV_CC_GetFloatValue(m_hDevHandle, "Gain", &picParam);
	if (tempValue != 0) {
		return 1;				//��ȡ����ʧ��
	}
	temp = picParam.fCurValue;
	return 0;
}

//�����ع�ʱ��
int HK_Fuc::setExposure(float currentValue) {
	int tempValue = MV_CC_SetFloatValue(m_hDevHandle, "ExposureTime", currentValue);
	if (tempValue != 0) {
		return 1;				//�����ع�ʧ��
	}
	return 0;
}

//��������
int HK_Fuc::setGain(float currentValue) {
	int tempValue = MV_CC_SetFloatValue(m_hDevHandle, "Gain", currentValue);
	if (tempValue != 0) {
		return 1;				//��������ʧ��
	}
	return 0;
}

//deleteָ��
void HK_Fuc::delM() {
	delete pDate;
	pDate = nullptr;
	delete m_pBufForSaveImage;
	m_pBufForSaveImage = nullptr;
}