#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T09:34:03
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = POSL
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(modules/include.pri)
include(data/include.pri)
include(computation/include.pri)
include(operators/include.pri)
include(benchmarks/include.pri)


SOURCES += main.cpp \
    solver.cpp \
    factory_compound_module.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    solver.h \
    factory_compound_module.h
