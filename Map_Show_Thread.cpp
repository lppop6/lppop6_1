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
	//只适用于我这边的地图坐标
	//slider里面，x轴的值与地图坐标的Y值成一定的关系。						X =  5 * x + 15
	//slider里面，y轴的值与地图坐标的X值成一定的关系。						Y = 515 - 5 * y
	//需要放置图片的基准是左上角,所以这边给加上15的偏差来进行图片的定位
	//所以图片X、Y轴要各减去15
	p.drawImage((5 * x), (500 - 5 * y), Position);
	p.end();
	emit send_Map(temp);
}

//首先是地图的底----地图的底可以进行不断地更新
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