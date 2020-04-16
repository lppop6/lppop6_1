#include "LabelMap.h"
#include <QMouseEvent>


LabelMap::LabelMap(QWidget* parent) :QLabel(parent) {
	this->setMouseTracking(true);
}

//自定义控件功能：将鼠标点击在控件（label）上的点传输给
void LabelMap::mousePressEvent(QMouseEvent* ev) {
	int x = ev->x();
	int y = ev->y();
	emit send_X_Y(x, y);
}
