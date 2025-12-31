#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QFontDatabase::addApplicationFont(":/fonts/balatro.otf");

	MainWindow w;
	w.show();

	return app.exec();
}
