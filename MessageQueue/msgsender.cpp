#include "msgsender.h"
#include <QUdpSocket>
#include <QTimer>
#include <QDebug>
MsgSender::MsgSender(QObject *parent) : QObject(parent),messageNo(1)
{
    timer = new QTimer(this);
    msgSender = new QUdpSocket(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(sendMsg()));
    timer->start(3000);
    qDebug() << "start sender";
}

void MsgSender::sendMsg()
{
    QByteArray datagram = "Multicast message " + QByteArray::number(messageNo);
    msgSender->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress("192.168.1.108"), 45454);
    ++messageNo;
}

