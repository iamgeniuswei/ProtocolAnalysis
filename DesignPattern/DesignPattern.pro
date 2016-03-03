#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T15:08:11
#
#-------------------------------------------------

QT       -= gui

TARGET = DesignPattern
TEMPLATE = lib

DEFINES += DESIGNPATTERN_LIBRARY

SOURCES += designpattern.cpp

HEADERS += designpattern.h\
        designpattern_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
