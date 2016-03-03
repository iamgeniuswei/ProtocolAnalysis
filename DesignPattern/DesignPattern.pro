#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T15:08:11
#
#-------------------------------------------------

QT       -= gui

TARGET = DesignPattern
TEMPLATE = lib

DEFINES += DESIGNPATTERN_LIBRARY

SOURCES += designpattern.cpp \
    observer.cpp \
    subject.cpp \
    clocktimer.cpp

HEADERS += designpattern.h\
        designpattern_global.h \
    observer.h \
    subject.h \
    clocktimer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
