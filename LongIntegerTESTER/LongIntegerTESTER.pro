#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T14:34:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = LongIntegerTESTER

CONFIG   += console
CONFIG   -= app_bundle

QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = app

HEADERS += ../LongInteger/long_int.h \
            ../LongInteger/merged_longint.h

SOURCES += main.cpp \
            ../LongInteger/long_int.cpp \
            ../LongInteger/merged_longint.cpp








