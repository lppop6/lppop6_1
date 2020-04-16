#pragma once

#include <QObject>
#include <qimage.h>
#include "HK_Fuc.h"
#include <qtimer.h>
#include <qthread.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include "Global_Val.h"

//extern cv::Mat wantedPic;			//想要保存的图像

class Show_Thread : public QObject
{
	Q_OBJECT

public:
	Show_Thread(QObject *parent = nullptr);
	~Show_Thread();

	void set_Flag(bool flag = true);
	void show_Pic();

	//void make_File_Folder();	//在电脑内生成一个文件夹

	int save_BMP();				//返回值用作标记储存图片名称，用于MessageBox显示
	int save_JPG();				

	bool is_Save();				//判断图像是否保存
	
	//消息框
	//QMessageBox* msgBox;
private:
	HK_Fuc* hkCamera = HK_Fuc::getInstance();
	bool isStop;				//进行采集图像的标识符
	cv::Mat wantedPic;			//想要保存的图像
	bool isData;				//来判断图像是否保存（通过是否有数据进入wantedPic）
	bool isIn;					//由于主线程的函数比子线程先一步运行，此时使用这个bool值来避免出错
	int picNumberJPG;			//用来作为存储JPG图像名称的一个标志,
								//但是使用static来声明会出错,这是由于静态成员属于整个类，而不是类的某个对象
								//如果要在类中使用的话推荐使用静态局部变量
	int picNumberBMP;			//用来作为存储BMP图像名称的一个标志
signals:
	void update_Show(QImage tempImg);

public slots:

};
