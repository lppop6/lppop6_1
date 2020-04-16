#include "SUB_IQA_1.h"
#include "qdebug.h"

using namespace cv;
using namespace std;

SUB_IQA_1::SUB_IQA_1(QWidget* parent) :
	QMainWindow(parent) 
{
	ui.setupUi(this);
	//�ź����
	connect(ui.btn_1, &QPushButton::clicked, 
		[=]{
			ui.btn_1->setEnabled(false);
			Pic_1 = true;
		});
	connect(ui.btn_2, &QPushButton::clicked,
		[=]{
			ui.btn_2->setEnabled(false);
			Pic_2 = true;
		});
	connect(ui.btn_3, &QPushButton::clicked,
		[=] {
			ui.btn_3->setEnabled(false);
			Pic_3 = true;
		});
	connect(ui.btn_Rechose, &QPushButton::clicked,
		[=] {
			ui.btn_1->setEnabled(true);
			ui.btn_2->setEnabled(true);
			ui.btn_3->setEnabled(true);
			Pic_1 = Pic_2 = Pic_3 = false;
		});
	connect(ui.btn_chose, &QPushButton::clicked,
		[=] {
			w2.show();
			w2.showMaximized();
			this->close();
		});
	connect(this, &SUB_IQA_1::send_Pic_IQA_1, &w2, &SUB_IQA_2::get_Pic_IQA);
}
//��ʵ��������˹��
Mat SUB_IQA_1::Gussi_Sharpen(Mat input) {
	if (input.empty()) {
		return input;
	}
	Mat result;
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(input, result, CV_32F, kernel);
	convertScaleAbs(result, result);
	return result;
	//UMS��
	//Mat blur, usm;
	//GaussianBlur(input, blur, Size(0, 0), 25);
	//addWeighted(input, 1.5, blur, -0.5, 0, usm);
	//return usm;
}
//��˹ģ��
Mat SUB_IQA_1::Gussi_Obscure(Mat input) {
	if (input.empty()) {
		return input;
	}
	Mat result;
	GaussianBlur(input, result, Size(5, 5), 0, 0, 0);
	GaussianBlur(result, result, Size(5, 5), 0, 0, 0);
	return result;
	
}
//MatתQImage
QImage SUB_IQA_1::Mat_to_Qimage(Mat input) {
	QImage result;
	if (input.empty()) {
		return result;
	}
	Mat tmpPic;
	if (input.channels() == 3) {
		cvtColor(input, tmpPic, CV_BGR2RGB);
		//QImage tImage = QImage((const unsigned char*)(tmpPic.data), tmpPic.cols, tmpPic.rows, QImage::Format_RGB888);
		result = QImage(const_cast<const unsigned char*>(tmpPic.data), tmpPic.cols, tmpPic.rows, tmpPic.cols* tmpPic.channels(), QImage::Format_RGB888);
		result.bits();
	}
	else {
		result = QImage(const_cast<const unsigned char*>(input.data), input.cols, input.rows, input.cols* input.channels(), QImage::Format_RGB888);
	}
	return result;
}
//���մ�DP���ڴ������ļ�·�����������з���
void SUB_IQA_1::Get_Path(QString ss) {
	//��QStringת��Ϊstring
	std::string str = ss.toStdString();
	str.c_str();
	//��·��ss����ͼƬ
	Mat t = imread(str);
	//��ͼƬ��������ģ��
	Mat t1 = Gussi_Sharpen(t);
	Mat t2 = Gussi_Obscure(t);
	//��Matת��ΪQImage
	QImage s =Mat_to_Qimage(t);
	emit send_Pic_IQA_1(s);						//��ת��ΪQIMage��ͼ�񷢸���һ���������۵Ĵ���
	
	//��������ͼƬ��ʾ�ڴ����ϣ�������ͼƬ�Ĵ�С
	//ͼƬ�����ҷֱ���ԭͼ����ͼ��ģ��ͼ
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic1->setPixmap(QPixmap::fromImage(s));
	s = Mat_to_Qimage(t1);
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic2->setPixmap(QPixmap::fromImage(s));
	s = Mat_to_Qimage(t2);
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic3->setPixmap(QPixmap::fromImage(s));
}