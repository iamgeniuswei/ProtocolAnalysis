#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPointer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    //Test QPointer

//    QPointer *pointer = new QPointer;
//    qDebug() << pointer;

//    QPointer<QLabel> label;
//    qDebug() << label;
//    QLabel *plabel = new QLabel;
//    plabel->setText("&Status");
//    qDebug() << label;
//    qDebug() << plabel;

//    label = plabel;

//    delete plabel;
//    qDebug() << plabel;
//    qDebug() << label;
//    qDebug() << label.isNull();

    QPointer<QLabel> label = new QLabel;

    QLabel *plbl = new QLabel;

    if (label== plbl)

    {

        qDebug("equal pointer....");

    }

    else

    {

        qDebug("not equal pointer....");

    }

    label = plbl;

    if (label== plbl)

    {

        qDebug("equal pointer....");

    }

    else

    {

        qDebug("not equal pointer....");

    }

    return a.exec();
}
