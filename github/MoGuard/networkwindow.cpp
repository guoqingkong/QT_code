#include "networkwindow.h"
#include "ui_networkwindow.h"
#include <QMenuBar>


//#include <QtMaemo5>

Networkwindow::Networkwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Networkwindow)
{
    ui->setupUi(this);

    QActionGroup *filterGroup = new QActionGroup(this);
    filterGroup->setExclusive(true);

    QAction *actEnable = new QAction(tr("Enabled"), filterGroup);
    actEnable->setCheckable(true);
    actEnable->setChecked(true);

    QAction *actDisable = new QAction(tr("Disabled"), filterGroup);
    actDisable->setCheckable(true);

    QAction *actWhatever = new QAction(tr("Whatever"), filterGroup);
    actWhatever->setCheckable(true);

    menuBar()->addActions(filterGroup->actions());

    menuBar()->addAction(tr("Action 1"));
    menuBar()->addAction(tr("Action 2"));
    menuBar()->addAction(tr("Action 3"));

//    QAction *checkAction = new QAction(tr("Checkable"), this);
//     checkAction->setCheckable(true);
//     menuBar()->addAction(checkAction);

//     menuBar()->addAction(new PickSelectorAction(this));

     setWindowTitle(tr("Network example"));

     getStatus();

}

Networkwindow::~Networkwindow()
{
    delete ui;
}

void Networkwindow::getStatus()
{
    systemInfo = new QSystemInfo(this);
    ui->label->setText(systemInfo->currentLanguage());

    di = new QSystemDeviceInfo(this);
    ui->progressBar->setValue(di->batteryLevel());

    ui->listWidget->addItem(di->imei());
    ui->listWidget->addItem(di->imsi());
    ui->listWidget->addItem(di->manufacturer());
    ui->listWidget->addItem(di->model());
    ui->listWidget->addItem(di->productName());

    QSystemDeviceInfo::InputMethodFlags methods = di->inputMethodType();
    QStringList inputs;
    if((methods & QSystemDeviceInfo::Keys)){
        inputs << "Keys";
    }
    if((methods & QSystemDeviceInfo::Keypad)) {
        inputs << "Keypad";
    }
    if((methods & QSystemDeviceInfo::Keyboard)) {
        inputs << "Keyboard";
    }
    if((methods & QSystemDeviceInfo::SingleTouch)) {
        inputs << "Touch Screen";
    }
    if((methods & QSystemDeviceInfo::MultiTouch)) {
        inputs << "Multi touch";
    }
    if((methods & QSystemDeviceInfo::Mouse)){
        inputs << "Mouse";
    }
    ui->listWidget->addItem(inputs.join(" "));
    int reIndex = 0;
     ni = new QSystemNetworkInfo(this);

     ui->listWidget_2->addItem(QString::number(ni->cellId()));
     ui->listWidget_2->addItem(QString::number(ni->locationAreaCode()));
     ui->listWidget_2->addItem(ni->currentMobileCountryCode());
     ui->listWidget_2->addItem(ni->currentMobileNetworkCode());
     ui->listWidget_2->addItem(ni->homeMobileCountryCode());
     ui->listWidget_2->addItem(ni->homeMobileNetworkCode());


     ui->listWidget_2->addItem(ni->networkName((QSystemNetworkInfo::NetworkMode)reIndex));
     ui->listWidget_2->addItem(ni->interfaceForMode((QSystemNetworkInfo::NetworkMode)reIndex).humanReadableName());

    ui->progressBar_2->setValue(ni->networkSignalStrength((QSystemNetworkInfo::NetworkMode)reIndex));


}

void Networkwindow::on_pushButton_clicked()
{
    delete ni;
    delete systemInfo;
    delete di;
    getStatus();
}
