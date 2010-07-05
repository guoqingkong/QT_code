#include "newwindow.h"
#include "ui_newwindow.h"

#include <QPointer>
#include <QMessageBox>
#include <QTimerEvent>
#include <QTimer>

QTM_USE_NAMESPACE

NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);

    // QMessageService class provides the interface
    // for requesting messaging service operations
    m_service = new QMessageService(this);
    QObject::connect(m_service,
        SIGNAL(messagesFound(const QMessageIdList&)),
        this,
        SLOT(messagesFound(const QMessageIdList&)));

    // QMessageManager class represents the main interface for storage and
    // retrieval of messages, folders and accounts in the system message store
    m_manager = new QMessageManager(this);

    // Listen new added messages
    QObject::connect(m_manager,
        SIGNAL(messageAdded(const QMessageId&,
        const QMessageManager::NotificationFilterIdSet&)),
        this,
        SLOT(messageAdded(const QMessageId&,
        const QMessageManager::NotificationFilterIdSet&)));

    // Create 2 filers set for filtering messages
    // - SMS filter
    // - InboxFolder filter
    m_notifFilterSet.insert( m_manager->registerNotificationFilter(
        QMessageFilter::byType(QMessage::Sms) &
        QMessageFilter::byStandardFolder(QMessage::InboxFolder)
        ));

    // Query messages
    //queryMessages();
}

NewWindow::~NewWindow()
{
    m_service->cancel();
    delete ui;
}

void NewWindow::queryMessages()
{
    // Create filers for query, we query SMS messages
    // that exists in the inbox folder
    QMessageFilter queryFilter(QMessageFilter::byType(QMessage::Sms) &
        QMessageFilter::byStandardFolder(QMessage::InboxFolder));

    m_service->queryMessages(queryFilter);
    // NOTE: qtSnippets::messagesFound() is called if messages found
}

void NewWindow::messagesFound(const QMessageIdList& ids)
{
    foreach(const QMessageId& id, ids)
        {
        // Get QMessage
        QMessage message = m_manager->message(id);
        // Get message string
        QString messageString = message.textContent();
        // Show to user
        QMessageBox::information(this,"Incoming SMS",messageString);
        }
}


void NewWindow::waitBeforeHandleMessage(const QMessageId& id)
{
    // We have to sleep a while to let SMS message to be ready for reading
    if (m_tid == 0) {
        m_messageId = id;
        m_tid = startTimer(3000);
    }
    else {
        this->killTimer(m_tid);
        m_tid = 0;
        m_tid = startTimer(3000);
    }
}

void NewWindow::timerEvent(QTimerEvent* event)
{
    if (m_tid == event->timerId()) {
        this->killTimer(m_tid);
        m_tid = 0;
        processIncomingSMS(m_messageId);
    }
}

void NewWindow::messageAdded(const QMessageId& id,
    const QMessageManager::NotificationFilterIdSet& matchingFilterIds)
{
    // Message added...
    if (matchingFilterIds.contains(m_notifFilterSet)) {
        // ...and it fits into our filters, lets process it
        waitBeforeHandleMessage(id);
        }
}

void NewWindow::processIncomingSMS(const QMessageId& id)
{
    QMessage message = m_manager->message(id);
    // SMS message body
    QString messageString = message.textContent();
    // Show message to user
    QMessageBox::information(this,"Incoming SMS",messageString);

    // Remove message from inbox
    m_manager->removeMessage(id);
}


void NewWindow::on_pushButton_clicked()
{

}
