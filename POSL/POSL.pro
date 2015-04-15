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


SOURCES += main.cpp \
    compound_module.cpp \
    operation_module.cpp \
    open_channel.cpp \
    domain.cpp \
    factory_domain.cpp \
    factory_n_int_domain.cpp \
    dom-interval.cpp \
    node.cpp \
    solution.cpp \
    ngbh_function.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    compound_module.h \
    operation_module.h \
    open_channel.h \
    domain.h \
    factory_domain.h \
    factory_n_int_domain.h \
    dom_interval.h \
    node.h \
    solution.h \
    ngbh_function.h \
    posl_iterator.h
