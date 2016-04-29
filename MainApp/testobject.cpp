#include "testobject.h"
#include <QDebug>
TestObject::TestObject(QObject *parent) : QObject(parent)
{
    qDebug() << this;
}

void TestObject::emitS()
{

    emitSignal();
}

