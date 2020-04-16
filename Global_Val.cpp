#include "Global_Val.h"

bool Pic_1 = false;
bool Pic_2 = false;
bool Pic_3 = false;

QImage gridMap = QImage(530, 530, QImage::Format_ARGB32);
QImage trackMap = QImage(530, 530, QImage::Format_ARGB32);
QImage Position = QImage("./control_test/Resources/Position.png");
QImage prePosition = QImage("./control_test/Resources/Position.png");
bool isFirstShow = true;
QString ss = "sssssssssssssssss";

QString filePath = " ";

//int ip1 = 