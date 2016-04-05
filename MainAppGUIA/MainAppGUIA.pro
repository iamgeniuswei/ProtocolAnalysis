#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T09:39:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainAppGUIA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/release/ -lMessageQueue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/debug/ -lMessageQueue
else:unix: LIBS += -L$$OUT_PWD/../MessageQueue/ -lMessageQueue

INCLUDEPATH += $$PWD/../MessageQueue
DEPENDPATH += $$PWD/../MessageQueue
