#include "msgserver.h"
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>
MsgServer::MsgServer(QObject *parent):
    QObject(parent)
{
    msgReciver = new QUdpSocket(this);
    msgReciver->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    connect(msgReciver, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));

}

void MsgServer::processPendingDatagrams()
{
    while (msgReciver->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(msgReciver->pendingDatagramSize());
        msgReciver->readDatagram(datagram.data(), datagram.size());
        qDebug() << "Received message: " << datagram;
    }
}

