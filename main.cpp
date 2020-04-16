#include "DP.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DP w;
	w.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	w.show();
	return a.exec();
}
