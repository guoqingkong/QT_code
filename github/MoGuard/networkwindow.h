#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QMainWindow>
#include <QtSystemInfo/QSystemNetworkInfo>
#include <QtSystemInfo/qsysteminfo.h>
QTM_USE_NAMESPACE

namespace Ui {
    class Networkwindow;
}

class Networkwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Networkwindow(QWidget *parent = 0);
    ~Networkwindow();

private:
    Ui::Networkwindow *ui;

    QSystemInfo *systemInfo;
    QSystemDeviceInfo *di;
    QSystemNetworkInfo *ni;

private:
    void getStatus();
private slots:

//    void tabChanged(int index);
//     void getVersion(int index);
//     void getFeature(int index);
//     void setSaverEnabled(bool b);
//     void updateDeviceLockedState();

//     void netStatusComboActivated(int);
//     void updateBatteryStatus(int);
//     void updatePowerState(QSystemDeviceInfo::PowerState);
//     void displayBatteryStatus(QSystemDeviceInfo::BatteryStatus);
//     void updateProfile(QSystemDeviceInfo::Profile profile);
//     void updateSimStatus();
//     void updateProfile();

//      void displayNetworkStatus(QSystemNetworkInfo::NetworkStatus);
//      void networkStatusChanged(QSystemNetworkInfo::NetworkMode, QSystemNetworkInfo::NetworkStatus);
//      void networkSignalStrengthChanged(QSystemNetworkInfo::NetworkMode, int);
//      void networkNameChanged(QSystemNetworkInfo::NetworkMode,const QString &);
//      void networkModeChanged(QSystemNetworkInfo::NetworkMode);

private slots:
    void on_pushButton_clicked();
};

#endif // NETWORKWINDOW_H
