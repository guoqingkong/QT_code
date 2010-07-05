#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtContacts/QContactManager>
#include <QDebug>
#include <QString>
#include <QContactFetchRequest>
#include <QContactPhoneNumber>
#include <Qt>
#include "dialog.h"

//#include "qtcontacts.h"

using namespace QtMobility;
QTM_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Maemo5StackedWindow);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s;
    s = ui->lineEdit->text();
    ui->listWidget->addItem(s);
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{

//    qDebug() << "The default manager for the platform is:" << cm.managerName();
//    qDebug() << "It" << (cm.isRelationshipTypeSupported(QContactRelationship::HasAssistant) ? "supports" : "does not support") << "assistant relationships.";
//    qDebug() << "It" << (cm.supportedContactTypes().contains(QContactType::TypeGroup) ? "supports" : "does not support") << "groups.";
//    qDebug() << "It" << (cm.hasFeature(QContactManager::MutableDefinitions) ? "supports" : "does not support") << "mutable detail definitions.";


    QList<QContactLocalId> contactIds = cm.contactIds();
    QContact a = cm.contact(contactIds.first());
    qDebug() << "Viewing the details of" << a.displayLabel();

    QList<QContactDetail> allDetails = a.details();
    for (int i = 0; i < allDetails.size(); i++) {
        QContactDetail detail = allDetails.at(i);
        QContactDetailDefinition currentDefinition = cm.detailDefinition(detail.definitionName());
        QMap<QString, QContactDetailFieldDefinition> fields = currentDefinition.fields();

        qDebug("\tDetail #%d (%s):", i, detail.definitionName().toAscii().constData());
        foreach (const QString& fieldKey, fields.keys()) {
            qDebug() << "\t\t" << fieldKey << "(" << fields.value(fieldKey).dataType() << ") =" << detail.value(fieldKey);
        }
        qDebug();
    }

    QContact b;
    QContactDetail de;
    foreach (const QContactLocalId& ids, contactIds )
        {
            b =  cm.contact(ids);
            de = b.detail("PhoneNumber");
            bool s = de.hasValue("PhoneNumber");
            qDebug()<< " has Value PhoneNumber key"<<s<<"|"<<de.value("PhoneNumber");
            QString show;
            show = b.displayLabel();
            show.append("\t");
            show.append(de.value("PhoneNumber"));
            ui->listWidget_2->addItem(show);
        }

}

void MainWindow::on_pushButton_5_clicked()
{
//    cm.contactsAdded();
    QContactFetchRequest m_contactFetchRequest;

//    connect(&m_contactFetchRequest, SIGNAL(stateChanged(QContactAbstractRequest::State)), this, SLOT(contactFetchRequestStateChanged(QContactAbstractRequest::State)));
//    m_contactFetchRequest.setManager(&cm);
//    m_contactFetchRequest.setFilter(QContactPhoneNumber::match("+447592020111"));
//    m_contactFetchRequest.start();

    QList<QContact> results = cm.contacts(QContactPhoneNumber::match("+447592020111"));;
    qDebug()<<"existing name is "<< results[0].displayLabel();
}

void MainWindow::on_pushButton_9_clicked()
{
    this->hide ();
    Dialog* dl = new Dialog();
    dl->show ();
}

void MainWindow::on_pushButton_6_clicked()
{
    if(nw.isNull())
    {
        nw = new NewWindow(this);
        nw->setAttribute(Qt::WA_Maemo5StackedWindow);
    }
    nw->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    if(nww.isNull())
    {
        nww =  new Networkwindow(this);
        nww->setAttribute(Qt::WA_Maemo5StackedWindow);
    }
    nww->show();
}
