#include "qplogsender.h"
#include <QDebug>
#include <QThread>
QPLogSender* QPLogSender::_instance = nullptr;

QPLogSender::QPLogSender(QObject *parent) : QObject(parent),logFile(nullptr)
{
//    _instance = this;
    connect(this, SIGNAL(msgSend(QString)), this, SLOT(msgHandle(QString)));
}

QPLogSender::~QPLogSender()
{
    if(logFile)
    {
        if(logFile->isOpen())
        {
            logFile->close();
        }
        logFile->deleteLater();
    }
}

QPLogSender *QPLogSender::getInstance()
{
    if(!_instance)
        _instance = new QPLogSender;
    return _instance;
}

void QPLogSender::sendMsg(const QString &msg)
{
    qDebug() << QThread::currentThread() << msg;
    QString s_msg = "MSG: " + msg;
    emit msgSend(s_msg);
}

void QPLogSender::sendError(const QString &error)
{
    qDebug() << QThread::currentThread() << error;
    QString s_msg = "ERR: " + error;
    emit msgSend(s_msg);
}

void QPLogSender::msgHandle(const QString &msg)
{
    qDebug() << QThread::currentThread() << msg;
}

