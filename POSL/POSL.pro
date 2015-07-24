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


SOURCES += src/main.cpp \
    src/modules/open_channel.cpp \
    src/data/domain.cpp \
    src/data/dStrategy/factory_n_int_domain.cpp \
    src/data/node.cpp \
    src/data/solution.cpp \
    src/benchmarks/benchmark.cpp \
    src/data/dom_interval.cpp \
    src/operators/operator.cpp \
    src/benchmarks/golfers.cpp \
    src/tools/long_int.cpp \
    src/tools/merged_longint.cpp \
    src/modules/om_random_conf_generation.cpp \
    src/modules/om_florian_random_conf_generation.cpp \
    src/data/neighborhood.cpp \
    src/data/one_element_changed_neighborhood.cpp \
    src/modules/om_one_element_changed_neighborhood.cpp \
    src/operators/sequential_exec_operator.cpp \
    src/data/seed.cpp \
    src/computation/not_implemented_parallel_strategy.cpp \
    src/computation/sequential_execution_sequential_strategy.cpp \
    src/modules/om_first_improvement_selection.cpp \
    src/modules/om_best_improvement_selection.cpp \
    src/data/decision_pair.cpp \
    src/data/dStrategy/strategy_search_in_neighborhood.cpp \
    src/data/dStrategy/best_improvement_v_search_state.cpp \
    src/data/dStrategy/v_search_state.cpp \
    src/modules/grouped_computation.cpp \
    src/modules/grouped_sequential_computation.cpp \
    src/modules/grouped_parallel_computation.cpp \
    src/data/dStrategy/first_improvement_v_search_state.cpp \
    src/testers/tester_cost_of_solution.cpp \
    src/testers/tester_random_configuration_generation.cpp \
    src/computation/random_configuration_generation_strategy.cpp \
    src/testers/tester_florian_random_configuration_generation.cpp \
    src/testers/tester_one_element_changed_neighborhood.cpp \
    src/testers/tester.cpp \
    src/testers/tester_first_improvement_selection.cpp \
    src/modules/om_fixed_first_configuration.cpp \
    src/tools/tools.cpp \
    src/testers/tester_best_improvement_selection.cpp \
    src/operators/binary_operator.cpp \
    src/computation/rho_sequential_strategy.cpp \
    src/operators/rho_operator.cpp \
    src/testers/tester_rho_operator.cpp \
    src/operators/unary_operator.cpp \
    src/solver/psp.cpp \
    src/expressions/iteretion_bound_expression.cpp \
    src/expressions/boolean_expression.cpp \
    src/operators/cyclic_operator.cpp \
    src/computation/cyclic_sequential_strategy.cpp \
    src/expressions/loop_bound_expression.cpp \
    src/testers/tester_cyclic_operator.cpp \
    src/modules/om_always_improve_decition.cpp \
    src/tools/rand_index_generator.cpp \
    src/testers/tester_sets_index_generator.cpp \
    src/data/dStrategy/elements_change_iterator.cpp \
    src/data/multi_elements_changed_neighborhood.cpp \
    src/modules/om_multi_elements_changed_neighborhood.cpp \
    src/testers/tester_multi_elements_changed_neighborhood.cpp \
    src/tools/matrix.cpp \
    src/data/union_neighborhood.cpp \
    src/data/dStrategy/union_iterator.cpp \
    src/operators/union_operator.cpp \
    src/computation/union_sequential_strategy.cpp \
    src/testers/tester_union_operator.cpp \
    src/operators/conditional_operator.cpp \
    src/computation/conditional_sequential_strategy.cpp \
    src/testers/tester_conditional_operator.cpp \
    src/expressions/reached_cost_expression.cpp \
    src/modules/om_simulated_annealing_decition.cpp \
    src/tools/randomizer.cpp \
    src/modules/om_random_selection.cpp \
    src/data/dStrategy/best_improvement_tabu_v_search_state.cpp \
    src/tools/tabu_list.cpp \
    src/modules/om_best_improvement_tabu_selection.cpp \
    src/testers/tester_random_selection.cpp \
    src/testers/tester_simulated_annealing_decition.cpp \
    src/testers/tester_best_improvement_tabu_selection.cpp \
    src/computation/random_permutation_by_blocks_generation_strategy.cpp \
    src/modules/om_random_conf_permutation_by_blocks_generation.cpp \
    src/testers/tester_random_permutation_configuration_generation.cpp \
    src/data/golfers_single_swap_neighborhood.cpp \
    src/modules/om_golfers_single_swap_neighborhood.cpp \
    src/data/dStrategy/decision_pair_packing_strategy.cpp \
    src/data/dStrategy/solution_packing_strategy.cpp \
    src/data/dStrategy/neighborhood_packing_strategy.cpp \
    src/data/dStrategy/one_element_changed_body_packing_strategy.cpp \
    src/data/dStrategy/multi_elements_changed_body_packing_strategy.cpp \
    src/data/dStrategy/golfers_single_swap_body_packing_strategy.cpp \
    src/testers/tester_golfers_permutation_neighborhood.cpp \
    src/testers/tester_packing_solution.cpp \
    src/testers/tester_packing_decision_pair.cpp \
    src/data/dStrategy/union_body_packing_strategy.cpp \
    src/testers/tester_packing_one_element_changed_neighborhood.cpp \
    src/testers/tester_packing_multi_changes_neighborhood.cpp \
    src/testers/tester_packing_golfers_permutation_neighborhood.cpp \
    src/testers/packing_neighborhood_tester.cpp \
    src/testers/tester_packing_union_neighborhood.cpp \
    src/computation/union_parallel_strategy.cpp \
    src/data/dStrategy/neighborhood_packing_from_pack_strategy.cpp \
    src/data/from_pack_neighborhood.cpp \
    src/operators/speed_operator.cpp \
    src/computation/speed_sequential_strategy.cpp \
    src/tools/chronometer.cpp \
    src/computation/speed_parallel_strategy.cpp \
    src/testers/tester_speed_operator.cpp \
    src/modules/compound_module_generator_from_code.cpp \
    src/packing/uncode_operator_strategy.cpp \
    src/packing/uncode_cyclic_operator_strategy.cpp \
    src/packing/uncode_compound_module_strategy.cpp \
    src/packing/uncode_sequential_grouper_strategy.cpp \
    src/packing/uncode_parallel_grouper_strategy.cpp \
    src/packing/uncode_operation_module_strategy.cpp \
    src/packing/uncode_bool_expression_strategy.cpp \
    src/packing/uncode_conditional_operator_strategy.cpp \
    src/packing/uncode_binary_operator_strategy.cpp \
    src/packing/uncode_rho_operator_strategy.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    src/modules/compound_module.h \
    src/modules/operation_module.h \
    src/modules/open_channel.h \
    src/data/domain.h \
    src/data/dStrategy/factory_domain.h \
    src/data/dStrategy/factory_n_int_domain.h \
    src/data/dom_interval.h \
    src/data/node.h \
    src/data/solution.h \
    src/data/dStrategy/posl_iterator.h \
    src/benchmarks/benchmark.h \
    src/modules/data_open_channel.h \
    src/modules/object_open_channel.h \
    src/operators/operator.h \
    src/benchmarks/golfers.h \
    src/tools/long_int.h \
    src/tools/merged_longint.h \
    src/modules/om_random_conf_generation.h \
    src/modules/om_florian_random_conf_generation.h \
    src/data/neighborhood.h \
    src/data/one_element_changed_neighborhood.h \
    src/modules/om_one_element_changed_neighborhood.h \
    src/operators/sequential_exec_operator.h \
    src/computation/sequential_computation_strategy.h \
    src/computation/computation_strategy.h \
    src/data/computation_data.h \
    src/data/seed.h \
    src/computation/not_implemented_parallel_strategy.h \
    src/computation/sequential_execution_sequential_strategy.h \
    src/modules/om_first_improvement_selection.h \
    src/modules/om_best_improvement_selection.h \
    src/data/decision_pair.h \
    src/computation/parallel_computation_strategy.h \
    src/data/dStrategy/strategy_search_in_neighborhood.h \
    src/data/dStrategy/best_improvement_v_search_state.h \
    src/data/dStrategy/v_search_state.h \
    src/modules/grouped_computation.h \
    src/modules/grouped_sequential_computation.h \
    src/modules/grouped_parallel_computation.h \
    src/data/dStrategy/first_improvement_v_search_state.h \
    src/testers/tester.h \
    src/testers/tester_cost_of_solution.h \
    src/testers/tester_random_configuration_generation.h \
    src/computation/random_configuration_generation_strategy.h \
    src/testers/tester_florian_random_configuration_generation.h \
    src/testers/tester_one_element_changed_neighborhood.h \
    src/testers/tester_first_improvement_selection.h \
    src/modules/om_fixed_first_configuration.h \
    src/tools/tools.h \
    src/testers/tester_best_improvement_selection.h \
    src/operators/binary_operator.h \
    src/computation/rho_sequential_strategy.h \
    src/operators/rho_operator.h \
    src/testers/tester_rho_operator.h \
    src/operators/unary_operator.h \
    src/solver/psp.h \
    src/expressions/iteretion_bound_expression.h \
    src/expressions/boolean_expression.h \
    src/operators/cyclic_operator.h \
    src/computation/cyclic_sequential_strategy.h \
    src/expressions/loop_bound_expression.h \
    src/testers/tester_cyclic_operator.h \
    src/modules/om_always_improve_decition.h \
    src/tools/rand_index_generator.h \
    src/testers/tester_sets_index_generator.h \
    src/data/dStrategy/elements_change_iterator.h \
    src/data/multi_elements_changed_neighborhood.h \
    src/modules/om_multi_elements_changed_neighborhood.h \
    src/testers/tester_multi_elements_changed_neighborhood.h \
    src/tools/matrix.h \
    src/data/union_neighborhood.h \
    src/data/dStrategy/union_iterator.h \
    src/operators/union_operator.h \
    src/computation/union_sequential_strategy.h \
    src/testers/tester_union_operator.h \
    src/operators/conditional_operator.h \
    src/computation/conditional_sequential_strategy.h \
    src/testers/tester_conditional_operator.h \
    src/expressions/reached_cost_expression.h \
    src/modules/om_simulated_annealing_decition.h \
    src/tools/randomizer.h \
    src/modules/om_random_selection.h \
    src/data/dStrategy/best_improvement_tabu_v_search_state.h \
    src/tools/tabu_list.h \
    src/modules/om_best_improvement_tabu_selection.h \
    src/testers/tester_random_selection.h \
    src/testers/tester_simulated_annealing_decition.h \
    src/testers/tester_best_improvement_tabu_selection.h \
    src/computation/random_permutation_by_blocks_generation_strategy.h \
    src/modules/om_random_conf_permutation_by_blocks_generation.h \
    src/testers/tester_random_permutation_configuration_generation.h \
    src/data/golfers_single_swap_neighborhood.h \
    src/modules/om_golfers_single_swap_neighborhood.h \
    src/data/dStrategy/packable.h \
    src/data/dStrategy/packing_strategy.h \
    src/data/dStrategy/decision_pair_packing_strategy.h \
    src/data/dStrategy/solution_packing_strategy.h \
    src/data/dStrategy/neighborhood_packing_strategy.h \
    src/data/dStrategy/neighborhood_body_packing_strategy.h \
    src/data/dStrategy/one_element_changed_body_packing_strategy.h \
    src/data/dStrategy/multi_elements_changed_body_packing_strategy.h \
    src/data/dStrategy/golfers_single_swap_body_packing_strategy.h \
    src/testers/tester_golfers_permutation_neighborhood.h \
    src/testers/tester_packing_solution.h \
    src/testers/tester_packing_decision_pair.h \
    src/data/dStrategy/union_body_packing_strategy.h \
    src/testers/tester_packing_one_element_changed_neighborhood.h \
    src/testers/tester_packing_multi_changes_neighborhood.h \
    src/testers/tester_packing_golfers_permutation_neighborhood.h \
    src/testers/packing_neighborhood_tester.h \
    src/testers/tester_packing_union_neighborhood.h \
    src/computation/union_parallel_strategy.h \
    src/data/dStrategy/neighborhood_packing_from_pack_strategy.h \
    src/data/t_nchanges.h \
    src/data/from_pack_neighborhood.h \
    src/operators/speed_operator.h \
    src/computation/speed_sequential_strategy.h \
    src/tools/chronometer.h \
    src/computation/speed_parallel_strategy.h \
    src/testers/tester_speed_operator.h \
    src/modules/compound_module_generator_from_code.h \
    src/packing/codable.h \
    src/packing/uncode_operator_strategy.h \
    src/packing/uncode_cyclic_operator_strategy.h \
    src/packing/uncode_compound_module_strategy.h \
    src/packing/uncode_sequential_grouper_strategy.h \
    src/packing/uncode_parallel_grouper_strategy.h \
    src/packing/uncode_operation_module_strategy.h \
    src/packing/uncode_bool_expression_strategy.h \
    src/packing/uncode_conditional_operator_strategy.h \
    src/packing/uncode_binary_operator_strategy.h \
    src/packing/uncode_rho_operator_strategy.h

# MPI Settings
QMAKE_CXX = mpicxx
QMAKE_CXX_RELEASE = $$QMAKE_CXX
QMAKE_CXX_DEBUG = $$QMAKE_CXX
QMAKE_LINK = $$QMAKE_CXX
QMAKE_CC = mpicxx

QMAKE_CFLAGS += $$system(mpicc --showme:compile)
QMAKE_LFLAGS += $$system(mpicxx --showme:link)
QMAKE_CXXFLAGS += $$system(mpicxx --showme:compile) -DMPICH_IGNORE_CXX_SEEK
QMAKE_CXXFLAGS_RELEASE += $$system(mpicxx --showme:compile) -DMPICH_IGNORE_CXX_SEEK
