#include <QtGui/QApplication>
#include "mainwindow.h"
#include "context.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Context context;

    MainWindow* w = new MainWindow();
    w->setAttribute(Qt::WA_Maemo5StackedWindow);
    context.qo1 = w;
#if defined(Q_WS_S60)
    w->showMaximized();
#else
    w->show();
#endif

    return a.exec();
}
