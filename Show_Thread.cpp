#include "Show_Thread.h"
#include "qfile.h"
#include "qdir.h"

//cv::Mat wantedPic(4, 3, CV_8UC1);				//随意的赋一个初始值

Show_Thread::Show_Thread(QObject *parent)
	: QObject(parent)
{
	//初始化是否保存图像的标志符
	isData = true;
	isIn = false;	
	//初始化保存图像名字编号
	picNumberBMP = 0;
	picNumberJPG = 0;
}

Show_Thread::~Show_Thread()
{
}

void Show_Thread::set_Flag(bool flag) {
	//flag = false时show_Pic内部才能运转
	isStop = flag;
}


//保存BMP
int Show_Thread::save_BMP() {
	isIn = true;
	if (!wantedPic.data) {
		//qDebug() << "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		isData = false;
		return 0;
	}
	picNumberBMP++;
	string ss = filePath.toStdString() +"/Pic/PicBMP/BMP" + std::to_string(picNumberBMP) + ".bmp";
	imwrite(ss, wantedPic);
	isData = true;
	return picNumberBMP;
}

int Show_Thread::save_JPG() {
	//如果在采集图像的过程中进行保存的话，会出现wantedPic的值是一个常量的问题，这一点需要仔细研究下
	//第一次进行保存的时候，会显示messageBox为failed，但是明明保存了呀

	//像这种局部静态对象的话，是可以进行使用的，与全局变量类似，但是外部无法访问
	//static int picNumberJPG = 0;			
	isIn = true;
	if (!wantedPic.data) {
		isData = false;
		return 0;
	}
	picNumberJPG++;
	string ss = filePath.toStdString()+"/Pic/PicJPG/JPG" + std::to_string(picNumberJPG) + ".jpg";
	imwrite(ss, wantedPic);
	isData = true;
	return picNumberJPG;
}

bool Show_Thread::is_Save() {
	if (isIn) {
		return isData;
	}
	return false;
}

void Show_Thread::show_Pic() {
	while (!isStop) {
		Mat pic;
		Mat tmpPic;
		QThread::msleep(100);					//线程暂时休眠100ms
		hkCamera->readBuffer(pic);				//获取图像数据
		pic.copyTo(wantedPic);					//得到与pic一样的wantedPic矩阵
		//转换Mat到QImage
		cvtColor(pic, tmpPic, CV_BGR2RGB);
		//QImage tImage = QImage((const unsigned char*)(tmpPic.data), tmpPic.cols, tmpPic.rows, QImage::Format_RGB888);
		QImage tImage = QImage(const_cast<const unsigned char*>(tmpPic.data), tmpPic.cols, tmpPic.rows, QImage::Format_RGB888);
		tImage.bits();
		//使用opencv显示图像
		//imshow("ss", pic);
		//waitKey(1);
		hkCamera->delM();						//释放指针
		emit update_Show(tImage);
		if (isStop) {
			break;
		}
	}
}
