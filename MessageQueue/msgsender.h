#ifndef MSGSENDER_H
#define MSGSENDER_H

#include <QObject>

class MsgSender : public QObject
{
    Q_OBJECT
public:
    explicit MsgSender(QObject *parent = 0);

signals:

public slots:
};

#endif // MSGSENDER_H
