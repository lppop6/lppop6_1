#include "SUB_IQA_2.h"

SUB_IQA_2::SUB_IQA_2(QWidget* parent)
	:QMainWindow(parent) 
{
	ui.setupUi(this);
	connect(ui.btn_Submit, &QPushButton::clicked, this, &SUB_IQA_2::get_Result);
}
//��ô�SUB_IQA_1������QImage,��ʾ��lbl��
void SUB_IQA_2::get_Pic_IQA(QImage pic) {
	ui.lbl_Pic->setPixmap(QPixmap::fromImage(pic));
}
//�ӽ����radiobutton��ö�ͼƬ������
double SUB_IQA_2::evaluate() {
	double score;
	//�ж��Ƿ�����÷�
	if (ui.rdb_1->isChecked()) {
		score = 1;
	}
	else if (ui.rdb_2->isChecked()) {
		score = 2;
	}
	else if(ui.rdb_3->isChecked()){
		score = 3;
	}
	else if (ui.rdb_4->isChecked()) {
		score = 4;
	}
	else if (ui.rdb_5->isChecked()) {
		score = 5;
	}
	else {
		score = 0;
	}
	//���ӷ֣�ͨ��SUB_IQA_1��ȫ�ֱ����Ľ�������ж�
	if (Pic_1 && Pic_2 && (!Pic_3)) {
		score *= 1.2;
	}
	else if (Pic_1 && Pic_3 && (!Pic_2)) {
		score *= 0.8;
	}
	return score;
}
//��ʾ�������MessageBox��ʾ
void SUB_IQA_2::get_Result() {
	double result = evaluate();
	QString s;
	QString y;
	if (result >= 5) {
		y = y.fromLocal8Bit("�����ǳ��ã�");
	}
	else if (result >= 4) {
		y = y.fromLocal8Bit("����һ�㡣");
	}
	else if (result > 3) {
		y = y.fromLocal8Bit("�����൱һ�㡣");
	}
	else {
		y = y.fromLocal8Bit("û��������");
	}
	s = "��ͼƬ��������Ϊ��" + QString::number(result) + "/n" + y;
	QMessageBox::information(NULL, QString::fromLocal8Bit("�������")
		, QString::fromLocal8Bit("��ͼƬ��������Ϊ��%1\n").arg(result).append(y)
	);
}