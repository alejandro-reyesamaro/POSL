#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T15:29:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = LongInteger
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    long_int.cpp \
    merged_longint.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    long_int.h \
    merged_longint.h
