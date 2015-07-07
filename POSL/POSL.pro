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
    modules/compound_module.cpp \
    modules/open_channel.cpp \
    data/domain.cpp \
    data/factory_n_int_domain.cpp \
    data/node.cpp \
    data/solution.cpp \
    solver.cpp \
    benchmarks/benchmark.cpp \
    factory_compound_module.cpp \
    data/dom_interval.cpp \
    modules/data_open_channel.cpp \
    modules/object_open_channel.cpp \
    operators/operator.cpp \
    benchmarks/golfers.cpp \
    ../LongInteger/long_int.cpp \
    ../LongInteger/merged_longint.cpp \
    modules/om_random_conf_generation.cpp \
    modules/om_florian_random_conf_generation.cpp \
    data/neighborhood.cpp \
    data/one_element_changed_neighborhood.cpp \
    modules/om_one_element_changed_neighborhood.cpp \
    operators/sequential_exec_operator.cpp \
    data/seed.cpp \
    computation/not_implemented_parallel_strategy.cpp \
    computation/sequential_execution_sequential_strategy.cpp \
    modules/om_first_improvement_selection.cpp \
    modules/om_best_improvement_selection.cpp \
    data/decision_pair.cpp \
    data/strategy_search_in_neighborhood.cpp \
    data/best_improvement_v_search_state.cpp \
    data/v_search_state.cpp \
    modules/grouped_computation.cpp \
    modules/grouped_sequential_computation.cpp \
    modules/grouped_parallel_computation.cpp \
    data/first_improvement_v_search_state.cpp \
    testers/tester_cost_of_solution.cpp \
    testers/tester_random_configuration_generation.cpp \
    computation/random_configuration_generation_strategy.cpp \
    testers/tester_florian_random_configuration_generation.cpp \
    testers/tester_one_element_changed_neighborhood.cpp \
    testers/tester.cpp \
    testers/tester_first_improvement_selection.cpp \
    modules/om_fixed_first_configuration.cpp \
    tools/tools.cpp \
    testers/tester_best_improvement_selection.cpp \
    operators/binary_operator.cpp \
    computation/rho_sequential_strategy.cpp \
    operators/rho_operator.cpp \
    testers/tester_rho_operator.cpp \
    operators/unary_operator.cpp \
    solver/psp.cpp \
    expressions/iteretion_bound_expression.cpp \
    expressions/boolean_expression.cpp \
    operators/cyclic_operator.cpp \
    computation/cyclic_sequential_strategy.cpp \
    expressions/loop_bound_expression.cpp \
    testers/tester_cyclic_operator.cpp \
    modules/om_always_improve_decition.cpp \
    tools/rand_index_generator.cpp \
    testers/tester_sets_index_generator.cpp \
    data/elements_change_iterator.cpp \
    data/multi_elements_changed_neighborhood.cpp \
    modules/om_multi_elements_changed_neighborhood.cpp \
    testers/tester_multi_elements_changed_neighborhood.cpp \
    tools/matrix.cpp \
    data/union_neighborhood.cpp \
    data/union_iterator.cpp \
    operators/union_operator.cpp \
    computation/union_sequential_strategy.cpp \
    testers/tester_union_operator.cpp \
    operators/conditional_operator.cpp \
    computation/conditional_sequential_strategy.cpp \
    testers/tester_conditional_operator.cpp \
    expressions/reached_cost_expression.cpp \
    modules/om_simulated_annealing_decition.cpp \
    tools/randomizer.cpp \
    modules/om_random_selection.cpp \
    data/best_improvement_tabu_v_search_state.cpp \
    tools/tabu_list.cpp \
    modules/om_best_improvement_tabu_selection.cpp \
    testers/tester_random_selection.cpp \
    testers/tester_simulated_annealing_decition.cpp \
    testers/tester_best_improvement_tabu_selection.cpp \
    computation/random_permutation_by_blocks_generation_strategy.cpp \
    modules/om_random_conf_permutation_by_blocks_generation.cpp \
    testers/tester_random_permutation_configuration_generation.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    modules/compound_module.h \
    modules/operation_module.h \
    modules/open_channel.h \
    data/domain.h \
    data/factory_domain.h \
    data/factory_n_int_domain.h \
    data/dom_interval.h \
    data/node.h \
    data/solution.h \
    data/posl_iterator.h \
    solver.h \
    benchmarks/benchmark.h \
    factory_compound_module.h \
    modules/data_open_channel.h \
    modules/object_open_channel.h \
    operators/operator.h \
    benchmarks/golfers.h \
    ../LongInteger/long_int.h \
    ../LongInteger/merged_longint.h \
    modules/om_random_conf_generation.h \
    modules/om_florian_random_conf_generation.h \
    data/neighborhood.h \
    data/one_element_changed_neighborhood.h \
    modules/om_one_element_changed_neighborhood.h \
    operators/sequential_exec_operator.h \
    computation/sequential_computation_strategy.h \
    computation/computation_strategy.h \
    data/computation_data.h \
    data/seed.h \
    computation/not_implemented_parallel_strategy.h \
    computation/sequential_execution_sequential_strategy.h \
    modules/om_first_improvement_selection.h \
    modules/om_best_improvement_selection.h \
    data/decision_pair.h \
    computation/parallel_computation_strategy.h \
    data/strategy_search_in_neighborhood.h \
    data/best_improvement_v_search_state.h \
    data/v_search_state.h \
    modules/grouped_computation.h \
    modules/grouped_sequential_computation.h \
    modules/grouped_parallel_computation.h \
    data/first_improvement_v_search_state.h \
    testers/tester.h \
    testers/tester_cost_of_solution.h \
    testers/tester_random_configuration_generation.h \
    computation/random_configuration_generation_strategy.h \
    testers/tester_florian_random_configuration_generation.h \
    testers/tester_one_element_changed_neighborhood.h \
    testers/tester_first_improvement_selection.h \
    modules/om_fixed_first_configuration.h \
    tools/tools.h \
    testers/tester_best_improvement_selection.h \
    operators/binary_operator.h \
    computation/rho_sequential_strategy.h \
    operators/rho_operator.h \
    testers/tester_rho_operator.h \
    operators/unary_operator.h \
    solver/psp.h \
    expressions/iteretion_bound_expression.h \
    expressions/boolean_expression.h \
    operators/cyclic_operator.h \
    computation/cyclic_sequential_strategy.h \
    expressions/loop_bound_expression.h \
    testers/tester_cyclic_operator.h \
    modules/om_always_improve_decition.h \
    tools/rand_index_generator.h \
    testers/tester_sets_index_generator.h \
    data/elements_change_iterator.h \
    data/multi_elements_changed_neighborhood.h \
    modules/om_multi_elements_changed_neighborhood.h \
    testers/tester_multi_elements_changed_neighborhood.h \
    tools/matrix.h \
    data/union_neighborhood.h \
    data/union_iterator.h \
    operators/union_operator.h \
    computation/union_sequential_strategy.h \
    testers/tester_union_operator.h \
    operators/conditional_operator.h \
    computation/conditional_sequential_strategy.h \
    testers/tester_conditional_operator.h \
    expressions/reached_cost_expression.h \
    modules/om_simulated_annealing_decition.h \
    tools/randomizer.h \
    modules/om_random_selection.h \
    data/best_improvement_tabu_v_search_state.h \
    tools/tabu_list.h \
    modules/om_best_improvement_tabu_selection.h \
    testers/tester_random_selection.h \
    testers/tester_simulated_annealing_decition.h \
    testers/tester_best_improvement_tabu_selection.h \
    computation/random_permutation_by_blocks_generation_strategy.h \
    modules/om_random_conf_permutation_by_blocks_generation.h \
    testers/tester_random_permutation_configuration_generation.h
