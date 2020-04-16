#pragma once

#include <QObject>
#include <qimage.h>
#include "HK_Fuc.h"
#include <qtimer.h>
#include <qthread.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include "Global_Val.h"

//extern cv::Mat wantedPic;			//��Ҫ�����ͼ��

class Show_Thread : public QObject
{
	Q_OBJECT

public:
	Show_Thread(QObject *parent = nullptr);
	~Show_Thread();

	void set_Flag(bool flag = true);
	void show_Pic();

	//void make_File_Folder();	//�ڵ���������һ���ļ���

	int save_BMP();				//����ֵ������Ǵ���ͼƬ���ƣ�����MessageBox��ʾ
	int save_JPG();				

	bool is_Save();				//�ж�ͼ���Ƿ񱣴�
	
	//��Ϣ��
	//QMessageBox* msgBox;
private:
	HK_Fuc* hkCamera = HK_Fuc::getInstance();
	bool isStop;				//���вɼ�ͼ��ı�ʶ��
	cv::Mat wantedPic;			//��Ҫ�����ͼ��
	bool isData;				//���ж�ͼ���Ƿ񱣴棨ͨ���Ƿ������ݽ���wantedPic��
	bool isIn;					//�������̵߳ĺ��������߳���һ�����У���ʱʹ�����boolֵ���������
	int picNumberJPG;			//������Ϊ�洢JPGͼ�����Ƶ�һ����־,
								//����ʹ��static�����������,�������ھ�̬��Ա���������࣬���������ĳ������
								//���Ҫ������ʹ�õĻ��Ƽ�ʹ�þ�̬�ֲ�����
	int picNumberBMP;			//������Ϊ�洢BMPͼ�����Ƶ�һ����־
signals:
	void update_Show(QImage tempImg);

public slots:

};
