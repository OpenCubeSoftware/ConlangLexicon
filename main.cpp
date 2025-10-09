#include "mainwindow.h"
#include "landingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
		QApplication a(argc, argv);
		MainWindow w;
		w.setWindowTitle("Big purrrrs");
		// w.show();
		return a.exec();
}
