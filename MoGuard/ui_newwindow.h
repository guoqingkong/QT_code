/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created: Wed Jun 30 11:14:21 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWindow
{
public:
    QAction *actionAbout_1;
    QAction *actionConfig;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewWindow)
    {
        if (NewWindow->objectName().isEmpty())
            NewWindow->setObjectName(QString::fromUtf8("NewWindow"));
        actionAbout_1 = new QAction(NewWindow);
        actionAbout_1->setObjectName(QString::fromUtf8("actionAbout_1"));
        actionConfig = new QAction(NewWindow);
        actionConfig->setObjectName(QString::fromUtf8("actionConfig"));
        centralwidget = new QWidget(NewWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(220, 30, 221, 251));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(460, 60, 81, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 191, 251));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 10, 54, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 54, 12));
        NewWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 575, 23));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        NewWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(NewWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout_1);
        menuAbout->addAction(actionConfig);
        menuAbout->addSeparator();

        retranslateUi(NewWindow);

        QMetaObject::connectSlotsByName(NewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NewWindow)
    {
        NewWindow->setWindowTitle(QApplication::translate("NewWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAbout_1->setText(QApplication::translate("NewWindow", "about 1", 0, QApplication::UnicodeUTF8));
        actionConfig->setText(QApplication::translate("NewWindow", "config", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("NewWindow", "clear", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewWindow", "return", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewWindow", "Content", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewWindow", "Item list", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("NewWindow", "about", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewWindow: public Ui_NewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
