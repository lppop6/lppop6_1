#include "LabelMap.h"
#include <QMouseEvent>


LabelMap::LabelMap(QWidget* parent) :QLabel(parent) {
	this->setMouseTracking(true);
}

//�Զ���ؼ����ܣ���������ڿؼ���label���ϵĵ㴫���
void LabelMap::mousePressEvent(QMouseEvent* ev) {
	int x = ev->x();
	int y = ev->y();
	emit send_X_Y(x, y);
}
