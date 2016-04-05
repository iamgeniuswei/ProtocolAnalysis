#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T09:28:24
#
#-------------------------------------------------

QT       += core network gui

TARGET = MainAppB
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/release/ -lMessageQueue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/debug/ -lMessageQueue
else:unix: LIBS += -L$$OUT_PWD/../MessageQueue/ -lMessageQueue

INCLUDEPATH += $$PWD/../MessageQueue
DEPENDPATH += $$PWD/../MessageQueue
