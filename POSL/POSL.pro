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
    open_channel.cpp \
    domain.cpp \
    factory_n_int_domain.cpp \
    node.cpp \
    solution.cpp \
    solver.cpp \
    benchmark.cpp \
    factory_compound_module.cpp \
    dom_interval.cpp \
    data_open_channel.cpp \
    object_open_channel.cpp \
    operator.cpp \
    golfers.cpp \
    ../LongInteger/long_int.cpp \
    ../LongInteger/merged_longint.cpp \
    om_random_conf_generation.cpp \
    om_florian_random_conf_generation.cpp \
    neighborhood.cpp \
    one_element_changed_neighborhood.cpp \
    om_one_element_changed_neighborhood.cpp \
    sequential_exec_operator.cpp \
    sequential_computation_strategy.cpp \
    parallel_computation_strategy.cpp \
    computation_strategy.cpp

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
    posl_iterator.h \
    solver.h \
    benchmark.h \
    factory_compound_module.h \
    data_open_channel.h \
    object_open_channel.h \
    operator.h \
    golfers.h \
    ../LongInteger/long_int.h \
    ../LongInteger/merged_longint.h \
    om_random_conf_generation.h \
    om_florian_random_conf_generation.h \
    neighborhood.h \
    one_element_changed_neighborhood.h \
    om_one_element_changed_neighborhood.h \
    sequential_exec_operator.h \
    sequential_computation_strategy.h \
    parallelc_omputation_strategy.h \
    computation_strategy.h \
    computation_data.h
