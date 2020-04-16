#pragma once
#include <qimage.h>
#include "qstring.h"
//全局变量

//用于主观评价--判断点击了哪几张图片
extern bool Pic_1;
extern bool Pic_2;
extern bool Pic_3;
//用于设置IP地址
extern int ip;

//用于运动控制
extern QImage gridMap;				//用于存储全局网格地图
extern QImage trackMap;				//用于存储全局轨迹地图
extern QImage Position;				//现在的定位点
extern QImage prePosition;			//先前的定位点
extern bool isFirstShow;			//判断是否第一次显示地图
extern QString ss;

extern bool isGetPic;				//判断是否获得了地图图片
extern bool isGetTrack;				//判断是否获得了轨迹

//用于获取当前应用程序的路径，用来生成一个文件夹来保存采集到的图片
extern QString filePath;

class Global_Val
{
};

