#pragma once
#include <qimage.h>
#include "qstring.h"
//ȫ�ֱ���

//������������--�жϵ�����ļ���ͼƬ
extern bool Pic_1;
extern bool Pic_2;
extern bool Pic_3;
//��������IP��ַ
extern int ip;

//�����˶�����
extern QImage gridMap;				//���ڴ洢ȫ�������ͼ
extern QImage trackMap;				//���ڴ洢ȫ�ֹ켣��ͼ
extern QImage Position;				//���ڵĶ�λ��
extern QImage prePosition;			//��ǰ�Ķ�λ��
extern bool isFirstShow;			//�ж��Ƿ��һ����ʾ��ͼ
extern QString ss;

extern bool isGetPic;				//�ж��Ƿ����˵�ͼͼƬ
extern bool isGetTrack;				//�ж��Ƿ����˹켣

//���ڻ�ȡ��ǰӦ�ó����·������������һ���ļ���������ɼ�����ͼƬ
extern QString filePath;

class Global_Val
{
};

