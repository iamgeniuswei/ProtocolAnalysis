#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T08:57:48
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = MessageQueue
TEMPLATE = lib

DEFINES += MESSAGEQUEUE_LIBRARY

SOURCES += messagequeue.cpp

HEADERS += messagequeue.h\
        messagequeue_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
