#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T09:49:56
#
#-------------------------------------------------

QT       += core network concurrent

QT       -= gui

TARGET = MainApp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qplogsender.cpp \
    stack.cpp \
    animal.cpp \
    qojecttest.cpp \
    testobject.cpp \
    testobject2.cpp \
    testobject3.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/release/ -lMessageQueue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MessageQueue/debug/ -lMessageQueue
else:unix: LIBS += -L$$OUT_PWD/../MessageQueue/ -lMessageQueue

INCLUDEPATH += $$PWD/../MessageQueue
DEPENDPATH += $$PWD/../MessageQueue

HEADERS += \
    qplogsender.h \
    stack.h \
    animal.h \
    qojecttest.h \
    testobject.h \
    testobject2.h \
    testobject3.h
