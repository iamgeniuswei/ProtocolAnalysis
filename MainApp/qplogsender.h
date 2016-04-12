#ifndef QPLOGSENDER_H
#define QPLOGSENDER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
class QPLogSender : public QObject
{
    Q_OBJECT
public:
    explicit QPLogSender(QObject *parent = 0);
    ~QPLogSender();

    //TODO
    static QPLogSender *getInstance();
    void sendMsg(const QString& msg);
    void sendError(const QString& error);


signals:
    void msgSend(const QString& msg);
public slots:
    void msgHandle(const QString& msg);

private:
    static QPLogSender *_instance;
    QFile *logFile;
    QTextStream logStream;
};

#endif // QPLOGSENDER_H
