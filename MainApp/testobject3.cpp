#include "testobject3.h"
#include <QDebug>
TestObject3::TestObject3(QObject *parent) : QObject(parent)
{

    qDebug() << this;
}

void TestObject3::receiveSignal()
{
    QObject *SigSender = QObject::sender();
    qDebug() << SigSender;
}

