#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QMainWindow>
#include <QPointer>

#include <QtMessaging/QMessageId>
#include <qmessage.h>
#include <qmessageservice.h>
#include <qmessagemanager.h>

QTM_USE_NAMESPACE

namespace Ui {
    class NewWindow;
}

class NewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = 0);
    ~NewWindow();
    // Execute query using filters
    void queryMessages();
    void timerEvent(QTimerEvent*);

private:
    Ui::NewWindow *ui;
    QPointer<QMessageService> m_service;
    QPointer<QMessageManager> m_manager;

    QMessageManager::NotificationFilterIdSet m_notifFilterSet;
    QMessageId m_messageId;
    int m_tid;

public slots:
    // Listens messagesFound() signal of QMessageService
    void messagesFound(const QMessageIdList&);

    // Listening signals from QMessageManager
    void messageAdded(const QMessageId&,
        const QMessageManager::NotificationFilterIdSet&);

private:
    void waitBeforeHandleMessage(const QMessageId& id);
    void processIncomingSMS(const QMessageId&);

private slots:
    void on_pushButton_clicked();
};

#endif // NEWWINDOW_H
