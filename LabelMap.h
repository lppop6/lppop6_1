#pragma once
#include <qlabel.h>
//自定义控件，用于运动控制界面的显示地图的label
//响应鼠标点击事件

class LabelMap :
	public QLabel
{
	Q_OBJECT
public:
	explicit LabelMap(QWidget* parent = 0);

	virtual void mousePressEvent(QMouseEvent* ev);
signals:
	void send_X_Y(int, int);
};

