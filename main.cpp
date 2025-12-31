#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

void LoadFont() {
	QFontDatabase::addApplicationFont(":/fonts/fonts/balatro.otf");
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	LoadFont();

	MainWindow w;
	w.show();

	return app.exec();
}
