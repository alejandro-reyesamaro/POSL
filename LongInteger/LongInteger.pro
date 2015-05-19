#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T14:24:50
#
#-------------------------------------------------

QT       -= core gui

TARGET = LongInteger
TEMPLATE = lib
CONFIG+= staticlib

DEFINES += LONGINTEGER_LIBRARY

SOURCES += \
    long_int.cpp \
    merged_longint.cpp

HEADERS +=\
        longinteger_global.h \
    long_int.h \
    merged_longint.h

QMAKE_CXXFLAGS += -std=c++11

unix {
    target.path = /usr/lib
    INSTALLS += target
}
