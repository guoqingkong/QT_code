#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtContacts/QContactManager>
#include <QPointer>
#include "newwindow.h"
#include "networkwindow.h"

using namespace QtMobility;

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QContactManager cm;
    QPointer<NewWindow> nw;
    QPointer<Networkwindow> nww;


private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
