#pragma once
#include "qobject.h"
#include "qstring.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class IQA_NF_Thread:public QObject
{
	Q_OBJECT
public:
	IQA_NF_Thread(QObject* parent = nullptr);
	~IQA_NF_Thread();
private:
	double Canny_Evaluate(cv::Mat);
	double Lap_Evaluate(cv::Mat);

public slots:
	void Get_Path(QString);
	
};

