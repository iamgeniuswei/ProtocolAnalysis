#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T15:01:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MainAppDP
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DesignPattern/release/ -lDesignPattern
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DesignPattern/debug/ -lDesignPattern
else:unix: LIBS += -L$$OUT_PWD/../DesignPattern/ -lDesignPattern

INCLUDEPATH += $$PWD/../DesignPattern
DEPENDPATH += $$PWD/../DesignPattern
