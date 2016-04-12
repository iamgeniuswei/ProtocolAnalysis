#include <QCoreApplication>
#include "msgserver.h"
#include <iostream>
#include <QDebug>
#include <QThread>
#include "qplogsender.h"
#include <QFuture>
#include <QtConcurrent>
#define gLoger QPLogSender::getInstance()
bool doSomething()
{
    for(int i=0; i< 10; i++)
    {
        gLoger->sendMsg(QString::number(i));
        qDebug() << QThread::currentThread();

    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    doSomething();
    QPLogSender *log;
    QThread worker;
    log->moveToThread(&worker);
    worker.start();

    /*QFuture<bool> future1 = */QtConcurrent::run(QThreadPool::globalInstance(),doSomething());
    /*QFuture<bool> future2 = */QtConcurrent::run(QThreadPool::globalInstance(),doSomething());
//    qDebug() << future1.result();
//    qDebug() << future2.result();


//    MsgServer *msgServer = new MsgServer;

//    while(std::cin.get())
//        {
//        qDebug() << "exit";
//    }

    return a.exec();
}
