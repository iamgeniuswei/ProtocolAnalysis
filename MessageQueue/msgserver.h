#ifndef MSGSERVER_H
#define MSGSERVER_H

#include <QObject>
#include <QHostAddress>
#include "messagequeue_global.h"
class QUdpSocket;
class MESSAGEQUEUESHARED_EXPORT MsgServer : public QObject
{
    Q_OBJECT
public:
    MsgServer(QObject *parent = 0);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *msgReciver;
    QHostAddress msgSeverHost;
};

#endif // MSGSERVER_H
