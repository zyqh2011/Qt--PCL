#include "Myshow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Myshow w;
	w.show();
	return a.exec();
}
