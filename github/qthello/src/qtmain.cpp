/*
 * Created: 07/02/10-17:20:23
 * Author: kangguoqing
 */
#include <QApplication>
#include <QPushButton>
#include <QtMaemo5>
#include <QMaemo5ValueButton>
#include <QMaemo5ListPickSelector>
#include "examplewidget.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

//        QMaemo5ValueButton hello("Hello world!");
//        hello.setFixedWidth(100);
//        hello.setFixedHeight(80);
//	hello.show();

//        QMaemo5ListPickSelector hellolist(NULL);
//        hello.set

        ExampleWidget w;
        w.setAttribute(Qt::WA_Maemo5StackedWindow);
        w.show();

	return app.exec();
}

