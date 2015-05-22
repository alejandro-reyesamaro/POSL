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
    computation_strategy.cpp \
    seed.cpp \
    not_implemented_parallel_strategy.cpp \
    sequential_execution_sequential_strategy.cpp \
    om_first_improvement_selection.cpp \
    om_best_improvement_selection.cpp \
    decision_pair.cpp \
    strategy_search_in_neighborhood.cpp \
    best_improvement_v_search_state.cpp \
    v_search_state.cpp

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
    computation_strategy.h \
    computation_data.h \
    seed.h \
    not_implemented_parallel_strategy.h \
    sequential_execution_sequential_strategy.h \
    om_first_improvement_selection.h \
    om_best_improvement_selection.h \
    decision_pair.h \
    parallel_computation_strategy.h \
    strategy_search_in_neighborhood.h \
    best_improvement_v_search_state.h \
    v_search_state.h
