#ifndef TESTOBJECT3_H
#define TESTOBJECT3_H

#include <QObject>

class TestObject3 : public QObject
{
    Q_OBJECT
public:
    explicit TestObject3(QObject *parent = 0);

signals:

public slots:
    void receiveSignal();
};

#endif // TESTOBJECT3_H
