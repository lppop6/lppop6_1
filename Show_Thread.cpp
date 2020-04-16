#include "Show_Thread.h"
#include "qfile.h"
#include "qdir.h"

//cv::Mat wantedPic(4, 3, CV_8UC1);				//����ĸ�һ����ʼֵ

Show_Thread::Show_Thread(QObject *parent)
	: QObject(parent)
{
	//��ʼ���Ƿ񱣴�ͼ��ı�־��
	isData = true;
	isIn = false;	
	//��ʼ������ͼ�����ֱ��
	picNumberBMP = 0;
	picNumberJPG = 0;
}

Show_Thread::~Show_Thread()
{
}

void Show_Thread::set_Flag(bool flag) {
	//flag = falseʱshow_Pic�ڲ�������ת
	isStop = flag;
}


//����BMP
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
	//����ڲɼ�ͼ��Ĺ����н��б���Ļ��������wantedPic��ֵ��һ�����������⣬��һ����Ҫ��ϸ�о���
	//��һ�ν��б����ʱ�򣬻���ʾmessageBoxΪfailed����������������ѽ

	//�����־ֲ���̬����Ļ����ǿ��Խ���ʹ�õģ���ȫ�ֱ������ƣ������ⲿ�޷�����
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
		QThread::msleep(100);					//�߳���ʱ����100ms
		hkCamera->readBuffer(pic);				//��ȡͼ������
		pic.copyTo(wantedPic);					//�õ���picһ����wantedPic����
		//ת��Mat��QImage
		cvtColor(pic, tmpPic, CV_BGR2RGB);
		//QImage tImage = QImage((const unsigned char*)(tmpPic.data), tmpPic.cols, tmpPic.rows, QImage::Format_RGB888);
		QImage tImage = QImage(const_cast<const unsigned char*>(tmpPic.data), tmpPic.cols, tmpPic.rows, QImage::Format_RGB888);
		tImage.bits();
		//ʹ��opencv��ʾͼ��
		//imshow("ss", pic);
		//waitKey(1);
		hkCamera->delM();						//�ͷ�ָ��
		emit update_Show(tImage);
		if (isStop) {
			break;
		}
	}
}
