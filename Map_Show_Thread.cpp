#include "Map_Show_Thread.h"

bool isGetPic = false;
bool isGetTrack = false;
//QImage trackPic = QImage(530, 530, QImage::Format_ARGB32);

Map_Show_Thread::Map_Show_Thread(QObject* parent)
	: QObject(parent)
{

}

Map_Show_Thread::~Map_Show_Thread() {

}

void Map_Show_Thread::map_update(int x, int y) {
	if (isFirstShow) {
		trackMap = gridMap;
	}
	QPainter p;
	QImage temp = trackMap;
	p.begin(&temp);
	//ֻ����������ߵĵ�ͼ����
	//slider���棬x���ֵ���ͼ�����Yֵ��һ���Ĺ�ϵ��						X =  5 * x + 15
	//slider���棬y���ֵ���ͼ�����Xֵ��һ���Ĺ�ϵ��						Y = 515 - 5 * y
	//��Ҫ����ͼƬ�Ļ�׼�����Ͻ�,������߸�����15��ƫ��������ͼƬ�Ķ�λ
	//����ͼƬX��Y��Ҫ����ȥ15
	p.drawImage((5 * x), (500 - 5 * y), Position);
	p.end();
	emit send_Map(temp);
}

//�����ǵ�ͼ�ĵ�----��ͼ�ĵ׿��Խ��в��ϵظ���
void Map_Show_Thread::show_Track(int x, int y, int X_Before, int Y_Before) {
	if (isFirstShow) {
		trackMap = gridMap;
		isFirstShow = false;
	}
	QImage temp = trackMap;
	QPainter p;
	p.begin(&temp);
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(Qt::darkGreen);
	p.drawLine(X_Before, Y_Before, (5 * x + 15), (515 - 5 * y));
	p.drawImage((X_Before - 15), (Y_Before - 15), prePosition);
	trackMap = temp;
	p.drawImage((5 * x), (500 - 5 * y), Position);
	p.end();
	emit send_Map(temp);
}