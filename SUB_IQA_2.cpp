#include "SUB_IQA_2.h"

SUB_IQA_2::SUB_IQA_2(QWidget* parent)
	:QMainWindow(parent) 
{
	ui.setupUi(this);
	connect(ui.btn_Submit, &QPushButton::clicked, this, &SUB_IQA_2::get_Result);
}
//获得从SUB_IQA_1传来的QImage,显示在lbl上
void SUB_IQA_2::get_Pic_IQA(QImage pic) {
	ui.lbl_Pic->setPixmap(QPixmap::fromImage(pic));
}
//从界面的radiobutton获得对图片的评分
double SUB_IQA_2::evaluate() {
	double score;
	//判断是否基础得分
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
	//附加分，通过SUB_IQA_1对全局变量的结果进行判断
	if (Pic_1 && Pic_2 && (!Pic_3)) {
		score *= 1.2;
	}
	else if (Pic_1 && Pic_3 && (!Pic_2)) {
		score *= 0.8;
	}
	return score;
}
//显示结果，由MessageBox显示
void SUB_IQA_2::get_Result() {
	double result = evaluate();
	QString s;
	QString y;
	if (result >= 5) {
		y = y.fromLocal8Bit("质量非常好！");
	}
	else if (result >= 4) {
		y = y.fromLocal8Bit("质量一般。");
	}
	else if (result > 3) {
		y = y.fromLocal8Bit("质量相当一般。");
	}
	else {
		y = y.fromLocal8Bit("没有质量。");
	}
	s = "该图片质量评分为：" + QString::number(result) + "/n" + y;
	QMessageBox::information(NULL, QString::fromLocal8Bit("分析结果")
		, QString::fromLocal8Bit("该图片质量评分为：%1\n").arg(result).append(y)
	);
}