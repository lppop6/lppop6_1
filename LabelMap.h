#pragma once
#include <qlabel.h>
//�Զ���ؼ��������˶����ƽ������ʾ��ͼ��label
//��Ӧ������¼�

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

