#include "SUB_IQA_1.h"
#include "qdebug.h"

using namespace cv;
using namespace std;

SUB_IQA_1::SUB_IQA_1(QWidget* parent) :
	QMainWindow(parent) 
{
	ui.setupUi(this);
	//信号与槽
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
//其实是拉普拉斯锐化
Mat SUB_IQA_1::Gussi_Sharpen(Mat input) {
	if (input.empty()) {
		return input;
	}
	Mat result;
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(input, result, CV_32F, kernel);
	convertScaleAbs(result, result);
	return result;
	//UMS锐化
	//Mat blur, usm;
	//GaussianBlur(input, blur, Size(0, 0), 25);
	//addWeighted(input, 1.5, blur, -0.5, 0, usm);
	//return usm;
}
//高斯模糊
Mat SUB_IQA_1::Gussi_Obscure(Mat input) {
	if (input.empty()) {
		return input;
	}
	Mat result;
	GaussianBlur(input, result, Size(5, 5), 0, 0, 0);
	GaussianBlur(result, result, Size(5, 5), 0, 0, 0);
	return result;
	
}
//Mat转QImage
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
//接收从DP窗口传来的文件路径，进而进行分析
void SUB_IQA_1::Get_Path(QString ss) {
	//将QString转化为string
	std::string str = ss.toStdString();
	str.c_str();
	//由路径ss载入图片
	Mat t = imread(str);
	//对图片进行锐化与模糊
	Mat t1 = Gussi_Sharpen(t);
	Mat t2 = Gussi_Obscure(t);
	//将Mat转化为QImage
	QImage s =Mat_to_Qimage(t);
	emit send_Pic_IQA_1(s);						//将转化为QIMage的图像发给下一个主观评价的窗口
	
	//将处理后的图片显示在窗口上，并设置图片的大小
	//图片从左到右分别是原图，锐化图，模糊图
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic1->setPixmap(QPixmap::fromImage(s));
	s = Mat_to_Qimage(t1);
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic2->setPixmap(QPixmap::fromImage(s));
	s = Mat_to_Qimage(t2);
	s = s.scaled(670,670, Qt::KeepAspectRatio);
	ui.lbl_Pic3->setPixmap(QPixmap::fromImage(s));
}