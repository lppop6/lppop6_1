#include "IQA_NF_Thread.h"
#include "qdebug.h"

using namespace std;
using namespace cv;

IQA_NF_Thread::IQA_NF_Thread(QObject *parent) {
	//qDebug() << "ssssssssssssssssssssssssssssssssssssss1";

}

IQA_NF_Thread::~IQA_NF_Thread() {

}

void IQA_NF_Thread::Get_Path(QString ss) {
	//std::string str = ss.toStdString();
	//str.c_str();
	//Mat input, gray_Input;
	//input = imread(str);
	//cvtColor(input, gray_Input, CV_BGR2GRAY);
	qDebug() << "ssssssssssssssssssssssssssssssssssssss";
	//qDebug() << Canny_Evaluate(input);
	//qDebug() << Lap_Evaluate(input);
}

double IQA_NF_Thread::Canny_Evaluate(Mat input) {
	double result;
	Mat result_Mat, mean, stddev;
	Canny(input, result_Mat, 200, 200);//canny±ßÔµ¼ì²â
	meanStdDev(input, mean, stddev);
	result = stddev.at<double>(0, 0);
	return result;
}

double IQA_NF_Thread::Lap_Evaluate(Mat input) {
	double result;
	Mat result_Mat, mean, stddev;
	Laplacian(input, result_Mat, CV_16U);
	meanStdDev(input, mean, stddev);
	result = stddev.at<double>(0,0);
	return result;
}