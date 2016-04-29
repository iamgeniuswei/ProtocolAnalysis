#ifndef QOJECTTEST_H
#define QOJECTTEST_H

#include <QObject>

class QOjectTest : public QObject
{
    Q_OBJECT
public:
    explicit QOjectTest(QObject *parent = 0);

signals:

public slots:
};

#endif // QOJECTTEST_H
