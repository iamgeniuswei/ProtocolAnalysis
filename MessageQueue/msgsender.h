#ifndef MSGSENDER_H
#define MSGSENDER_H

#include <QObject>
#include <QHostAddress>
#include "messagequeue_global.h"
class QUdpSocket;
class QTimer;
class MESSAGEQUEUESHARED_EXPORT MsgSender : public QObject
{
    Q_OBJECT
public:
    explicit MsgSender(QObject *parent = 0);

signals:

public slots:
    void sendMsg();

private:
    QUdpSocket *msgSender;
    QTimer *timer;
    QHostAddress *serverHost;
    int messageNo;
};

#endif // MSGSENDER_H
