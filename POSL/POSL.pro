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
    src/benchmarks/benchmark.cpp \
    src/benchmarks/golfers.cpp \
    src/benchmarks/squaring_square.cpp \
    src/benchmarks/golomb_ruler.cpp \
    src/benchmarks/n_queens.cpp \
    src/data/domain.cpp \
    src/data/dStrategy/factory_n_int_domain.cpp \
    src/data/node.cpp \
    src/data/solution.cpp \
    src/data/dom_interval.cpp \
    src/data/neighborhood.cpp \
    src/data/one_element_changed_neighborhood.cpp \
    src/data/seed.cpp \
    src/data/decision_pair.cpp \
    src/data/dStrategy/elements_change_iterator.cpp \
    src/data/multi_elements_changed_neighborhood.cpp \
    src/data/union_neighborhood.cpp \
    src/data/dStrategy/union_iterator.cpp \
    src/data/golfers_single_swap_neighborhood.cpp \
    src/data/from_pack_neighborhood.cpp \
    src/data/dStrategy/neighbor_selecting_best_improvement_tabu.cpp \
    src/data/dStrategy/neighbor_selecting_best_improvement.cpp \
    src/data/dStrategy/neighbor_selecting_first_improvement.cpp \
    src/data/dStrategy/neighbor_selecting_random.cpp \
    src/data/computation_data.cpp \
    src/data/one_sorted_change_neighborhood.cpp \
    src/data/multi_sorted_changes_neighborhood.cpp \
    src/data/one_permutation_neighborhood.cpp \
    src/modules/om_random_conf_generation.cpp \
    src/modules/om_one_element_changed_neighborhood.cpp \
    src/modules/om_first_improvement_selection.cpp \
    src/modules/om_best_improvement_selection.cpp \
    src/modules/grouped_computation.cpp \
    src/modules/grouped_sequential_computation.cpp \
    src/modules/grouped_parallel_computation.cpp \
    src/modules/om_multi_sorted_changes_neighborhood.cpp \
    src/modules/om_random_conf_ordered_generation.cpp \
    src/modules/compound_module_generator_from_code.cpp \
    src/modules/om_random_conf_permutation_by_blocks_generation.cpp \
    src/modules/om_best_improvement_tabu_selection.cpp \
    src/modules/om_random_selection.cpp \
    src/modules/om_multi_elements_changed_neighborhood.cpp \
    src/modules/om_fixed_first_configuration.cpp \
    src/modules/om_golfers_single_swap_neighborhood.cpp \
    src/modules/om_one_sorted_change_neighborhood.cpp \
    src/modules/aom_first_configuration_generation.cpp \
    src/modules/aom_neighborhood_function.cpp \
    src/modules/aom_selection_function.cpp \
    src/modules/aom_decision_function.cpp \
    src/modules/om_always_improve_decision.cpp \
    src/modules/om_simulated_annealing_decision.cpp \
    src/modules/data_open_channel.cpp \
    src/modules/solution_data_open_channel.cpp \
    src/modules/decision_pair_data_open_channel.cpp \
    src/modules/neighborhood_data_open_channel.cpp \
    src/modules/oms_time_counter.cpp \
    src/modules/oms_iterations_counter.cpp \        
    src/modules/strategy/random_configuration_generation_strategy.cpp \
    src/modules/strategy/random_permutation_by_blocks_generation_strategy.cpp \    
    src/modules/strategy/random_ordered_generation_strategy.cpp \
    src/modules/om_random_permutation_generation.cpp \
    src/modules/strategy/random_permutation_configuration_strategy.cpp \
    src/modules/om_one_permutation_neighborhood.cpp \
    src/computation/factory_computation_strategy_ra001.cpp \
    src/computation/factory_computation_strategy_sa001.cpp \
    src/computation/computation_strategy.cpp \
    src/computation/factory_computation_strategy_a001.cpp \
    src/computation/factory_computation_strategy_a002.cpp \
    src/computation/factory_computation_strategy_trivial.cpp \
    src/computation/flag_computation.cpp \
    src/computation/factory_computation_strategy_sa002.cpp \
    src/computation/factory_computation_strategy_ra002.cpp \
    src/testers/tester_random_configuration_generation.cpp \
    src/testers/tester_florian_random_configuration_generation.cpp \
    src/testers/tester_one_element_changed_neighborhood.cpp \
    src/testers/tester.cpp \
    src/testers/tester_first_improvement_selection.cpp \
    src/testers/tester_sets_index_generator.cpp \
    src/testers/tester_best_improvement_selection.cpp \
    src/testers/tester_cyclic_operator.cpp \
    src/testers/tester_multi_elements_changed_neighborhood.cpp \
    src/testers/tester_union_operator.cpp \
    src/testers/tester_conditional_operator.cpp \
    src/testers/tester_random_selection.cpp \
    src/testers/tester_simulated_annealing_decition.cpp \
    src/testers/tester_best_improvement_tabu_selection.cpp \
    src/testers/tester_rho_operator.cpp \
    src/testers/tester_random_permutation_configuration_generation.cpp \
    src/testers/tester_golfers_permutation_neighborhood.cpp \
    src/testers/tester_packing_solution.cpp \
    src/testers/tester_packing_decision_pair.cpp \
    src/testers/tester_packing_one_element_changed_neighborhood.cpp \
    src/testers/tester_packing_multi_changes_neighborhood.cpp \
    src/testers/tester_packing_golfers_permutation_neighborhood.cpp \
    src/testers/packing_neighborhood_tester.cpp \
    src/testers/tester_packing_union_neighborhood.cpp \
    src/testers/tester_speed_operator.cpp \
    src/testers/tester_random_ordered_confgeneration.cpp \
    src/testers/tester_cost_of_solution_golfers.cpp \
    src/testers/tester_cost_of_solution_golom_rules.cpp \
    src/testers/tester_cost_of_solution_quaring_square.cpp \
    src/testers/tester_solver_golfers.cpp \
    src/testers/tester_solver_golomb_ruler.cpp \
    src/testers/tester_solver_squaring_square.cpp \
    src/testers/tester_multi_sorted_changes_neighborhood.cpp \
    src/testers/tester_one_sorted_change_neighborhood.cpp \
    src/testers/tester_comunication.cpp \
    src/testers/tester_solver_n_queens.cpp \
    src/testers/tester_cost_of_solution_nqueens.cpp \
    src/operators/binary_operator.cpp \
    src/operators/unary_operator.cpp \
    src/operators/rho_operator.cpp \    
    src/operators/union_operator.cpp \
    src/operators/cyclic_operator.cpp \
    src/operators/speed_operator.cpp \
    src/operators/conditional_operator.cpp \
    src/operators/sequential_exec_operator.cpp \
    src/operators/operator.cpp \
    src/operators/send_data_operator.cpp \
    src/operators/min_operator.cpp \
    src/operators/strategy/not_implemented_parallel_strategy.cpp \
    src/operators/strategy/sequential_execution_sequential_strategy.cpp \
    src/operators/strategy/min_sequential_strategy.cpp \
    src/operators/strategy/min_parallel_strategy.cpp \
    src/operators/strategy/min_crit_comparison.cpp \
    src/operators/strategy/send_data_sequential_strategy.cpp \
    src/operators/strategy/conditional_sequential_strategy.cpp \
    src/operators/strategy/executer.cpp \
    src/operators/strategy/speed_parallel_strategy.cpp \
    src/operators/strategy/speed_sequential_strategy.cpp \
    src/operators/strategy/union_parallel_strategy.cpp \
    src/operators/strategy/union_sequential_strategy.cpp \
    src/operators/strategy/cyclic_sequential_strategy.cpp \
    src/operators/strategy/rho_sequential_strategy.cpp \
    src/operators/florian_operator.cpp \
    src/operators/strategy/florian_sequential_strategy.cpp \
    src/expressions/iteretion_bound_expression.cpp \
    src/expressions/boolean_expression.cpp \
    src/expressions/loop_bound_expression.cpp \
    src/expressions/reached_cost_expression.cpp \
    src/tools/randomizer.cpp \
    src/tools/tabu_list.cpp \
    src/tools/chronometer.cpp \
    src/tools/rand_index_generator.cpp \
    src/tools/long_int.cpp \
    src/tools/merged_longint.cpp \
    src/tools/matrix.cpp \
    src/tools/tools.cpp \
    src/packing/packers/decision_pair_packer.cpp \
    src/packing/packers/golfers_single_swap_packer.cpp \
    src/packing/packers/neighborhood_packer.cpp \
    src/packing/packers/multi_changes_neighborhood_packer.cpp \
    src/packing/packers/one_change_neighborhood_packer.cpp \
    src/packing/packers/solution_packer.cpp \
    src/packing/factory/factory_packer.cpp \
    src/packing/factory/factory_solution_packer.cpp \
    src/packing/factory/factory_decision_pair_packer.cpp \
    src/packing/factory/factory_one_change_neighborhood_packer.cpp \
    src/packing/factory/factory_multi_changes_neighborhood_packer.cpp \
    src/packing/factory/factory_golfers_single_swap_neighborhood_packer.cpp \
    src/packing/packers/packer.cpp \
    src/solver/posl_solver.cpp \
    src/solver/for_golfers_css.cpp \
    src/solver/for_squaring_square_css.cpp \
    src/solver/for_golomb_ruler_css.cpp \
    src/solver/posl_meta_solver.cpp \
    src/solver/psp.cpp \
    src/solver/comunicator.cpp \
    src/solver/for_n_queens_css.cpp \
    src/testers/tester_from_pack_neighborhood.cpp \
    src/solver/create_solver_strategy.cpp \
    src/data/dynamic_neighborhood.cpp \
    src/data/dStrategy/apply_change_behavior.cpp \
    src/data/dStrategy/single_swap_apply_change_behavior.cpp \
    src/data/dStrategy/standard_apply_change_behavior.cpp \
    src/data/dStrategy/sorted_apply_change_behavior.cpp \
    src/computation/factory_computation_strategy.cpp \
    src/packing/module_uncoder.cpp \
    src/benchmarks/cost_strategy/golfers_intersections_costs_trategy.cpp \
    src/benchmarks/cost_strategy/solution_cost_strategy.cpp \
    src/benchmarks/cost_strategy/golfers_long_int_cost_strategy.cpp \
    src/benchmarks/cost_strategy/golomb_ruler_distances_cost_strategy.cpp \
    src/benchmarks/cost_strategy/n_queens_daniel_cost_strategy.cpp \
    src/benchmarks/cost_strategy/squaring_square_superposition_cost_strategy.cpp \
    src/testers/tester_tabuselection.cpp \
    src/expressions/same_cost_iterations_bound_expression.cpp \
    src/expressions/or_expression.cpp \
    src/expressions/and_expression.cpp \
    src/benchmarks/cost_strategy/golfers_3pn_cost_strategy.cpp \
    src/testers/tester_longint.cpp \
    src/benchmarks/show_strategy/golfers_default_show_strategy.cpp \
    src/benchmarks/show_strategy/show_strategy.cpp \
    src/benchmarks/show_strategy/golomb_ruler_default_show_strategy.cpp \
    src/benchmarks/show_strategy/n_queens_default_show_strategy.cpp \
    src/benchmarks/show_strategy/squaring_square_default_show_strategy.cpp \
    src/benchmarks/relative_cost_strategy/relative_cost_strategy.cpp \
    src/benchmarks/relative_cost_strategy/golfers_relative_cost_strategy.cpp \
    src/benchmarks/relative_cost_strategy/squaring_square_relative_cost_strategy.cpp \
    src/benchmarks/relative_cost_strategy/golomb_ruler_relative_cost_strategy.cpp \
    src/benchmarks/relative_cost_strategy/nqueens_relative_cost_strategy.cpp \
    src/testers/tester_iteration_golfers.cpp \
    src/computation/factory_computation_strategy_a000.cpp \
    src/tools/connection_matrix.cpp \
    src/modules/operation_module.cpp \
    src/computation/factory_computation_strategy_ra000.cpp \
    src/computation/factory_computation_strategy_sa000.cpp \
    src/operators/strategy/min_och_sequential_strategy.cpp \
    src/computation/factory_computation_strategy_b001.cpp \
    src/solver/strategy/showing_result_strategy.cpp \
    src/solver/strategy/show_plain_result_strategy.cpp \
    src/solver/strategy/show_bechmark_result_strategy.cpp \
    src/solver/strategy/show_to_collect_strategy.cpp \
    src/tools/hash_map.cpp \
    src/modules/open_channel.cpp \
    src/tools/posl_tag.cpp \
    src/solver/posl_name_space.cpp \
    src/packing/compound_module_uncoder.cpp \
    src/packing/grouped_sequential_computation_uncoder.cpp \
    src/packing/grouped_parallel_computation_uncoder.cpp \
    src/packing/operation_module_uncoder.cpp \
    src/packing/om_s_uncoder.cpp \
    src/packing/om_v_uncoder.cpp \
    src/packing/om_ss_uncoder.cpp \
    src/packing/om_d_uncoder.cpp \
    src/packing/operator_uncoder.cpp \
    src/packing/operator_conditional_uncoder.cpp \
    src/packing/operator_cyclic_uncoder.cpp \
    src/packing/operator_flo_uncoder.cpp \
    src/packing/operator_rho_uncoder.cpp \
    src/packing/operator_send_uncoder.cpp \
    src/packing/boolean_expression_uncoder.cpp \
    src/packing/bool_expression_and_uncoder.cpp \
    src/packing/bool_expression_or_uncoder.cpp \
    src/testers/tester_coding_posl.cpp \
    src/tools/coding_tools.cpp \
    src/packing/open_channel_uncoder.cpp \
    src/connections/scheduler.cpp \
    src/connections/connection_operator_broadcasting.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    src/modules/compound_module.h \
    src/modules/operation_module.h \
    src/modules/open_channel.h \
    src/modules/data_open_channel.h \
    src/modules/object_open_channel.h \
    src/modules/om_random_conf_generation.h \
    src/modules/om_one_element_changed_neighborhood.h \
    src/modules/om_first_improvement_selection.h \
    src/modules/om_best_improvement_selection.h \
    src/modules/grouped_computation.h \
    src/modules/grouped_sequential_computation.h \
    src/modules/grouped_parallel_computation.h \
    src/modules/om_fixed_first_configuration.h \
    src/modules/om_random_selection.h \
    src/modules/om_random_conf_permutation_by_blocks_generation.h \
    src/modules/om_best_improvement_tabu_selection.h \
    src/modules/om_multi_elements_changed_neighborhood.h \
    src/modules/om_golfers_single_swap_neighborhood.h \
    src/modules/om_multi_sorted_changes_neighborhood.h \
    src/modules/om_one_sorted_change_neighborhood.h \
    src/modules/aom_first_configuration_generation.h \
    src/modules/aom_neighborhood_function.h \
    src/modules/aom_selection_function.h \
    src/modules/aom_decision_function.h \
    src/modules/om_always_improve_decision.h \
    src/modules/om_simulated_annealing_decision.h \
    src/modules/compound_module_generator_from_code.h \
    src/modules/oms_time_counter.h \
    src/modules/oms_iterations_counter.h \
    src/modules/om_random_conf_ordered_generation.h \
    src/modules/solution_data_open_channel.h \
    src/modules/decision_pair_data_open_channel.h \
    src/modules/neighborhood_data_open_channel.h \
    src/modules/strategy/random_ordered_generation_strategy.h \
    src/modules/strategy/random_configuration_generation_strategy.h \
    src/modules/strategy/random_permutation_by_blocks_generation_strategy.h \
    src/modules/om_random_permutation_generation.h \
    src/modules/strategy/random_permutation_configuration_strategy.h \
    src/modules/om_one_permutation_neighborhood.h \
    src/data/domain.h \
    src/data/dStrategy/factory_domain.h \
    src/data/dStrategy/factory_n_int_domain.h \
    src/data/dom_interval.h \
    src/data/node.h \
    src/data/solution.h \
    src/data/dStrategy/posl_iterator.h \
    src/data/decision_pair.h \
    src/data/neighborhood.h \
    src/data/one_element_changed_neighborhood.h \
    src/data/computation_data.h \
    src/data/seed.h \
    src/data/union_neighborhood.h \
    src/data/dStrategy/union_iterator.h \
    src/data/dStrategy/elements_change_iterator.h \
    src/data/multi_elements_changed_neighborhood.h \
    src/data/multi_sorted_changes_neighborhood.h \
    src/data/one_sorted_change_neighborhood.h \
    src/data/dStrategy/neighbor_selecting_best_improvement_tabu.h \
    src/data/dStrategy/neighbor_selecting_best_improvement.h \
    src/data/dStrategy/neighbor_selecting_first_improvement.h \
    src/data/dStrategy/neighbor_selecting_random.h \
    src/data/golfers_single_swap_neighborhood.h \
    src/data/from_pack_neighborhood.h \
    src/data/one_permutation_neighborhood.h \
    src/benchmarks/benchmark.h \
    src/benchmarks/golfers.h \
    src/benchmarks/squaring_square.h \
    src/benchmarks/golomb_ruler.h \
    src/benchmarks/n_queens.h \
    src/operators/operator.h \
    src/operators/binary_operator.h \
    src/operators/sequential_exec_operator.h \
    src/operators/rho_operator.h \
    src/operators/unary_operator.h \
    src/operators/cyclic_operator.h \
    src/operators/conditional_operator.h \
    src/operators/min_operator.h \
    src/operators/union_operator.h \
    src/operators/speed_operator.h \
    src/operators/send_data_operator.h \
    src/operators/strategy/not_implemented_parallel_strategy.h \    
    src/operators/strategy/sequential_execution_sequential_strategy.h \
    src/operators/strategy/union_sequential_strategy.h \
    src/operators/strategy/cyclic_sequential_strategy.h \
    src/operators/strategy/conditional_sequential_strategy.h \
    src/operators/strategy/rho_sequential_strategy.h \
    src/operators/strategy/execution_strategy.h \
    src/operators/strategy/sequential_execution_strategy.h \
    src/operators/strategy/parallel_execution_strategy.h \
    src/operators/strategy/executer.h \
    src/operators/strategy/send_data_sequential_strategy.h \
    src/operators/strategy/min_sequential_strategy.h \
    src/operators/strategy/min_parallel_strategy.h \
    src/operators/strategy/min_crit_comparison.h \
    src/operators/strategy/union_parallel_strategy.h \
    src/operators/strategy/speed_parallel_strategy.h \
    src/operators/strategy/speed_sequential_strategy.h \
    src/operators/florian_operator.h \
    src/operators/strategy/florian_sequential_strategy.h \
    src/computation/computation_strategy.h \
    src/computation/factory_computation_strategy.h \
    src/computation/factory_computation_strategy_a001.h \
    src/computation/factory_computation_strategy_a002.h \
    src/computation/factory_computation_strategy_trivial.h \
    src/computation/factory_computation_strategy_sa001.h \
    src/computation/factory_computation_strategy_ra001.h \
    src/computation/factory_computation_strategy_sa001.h \
    src/computation/factory_computation_strategy_ra001.h \
    src/computation/flag_computation.h \
    src/computation/factory_computation_strategy_sa002.h \
    src/computation/factory_computation_strategy_ra002.h \
    src/testers/tester.h \
    src/testers/tester_random_configuration_generation.h \
    src/testers/tester_florian_random_configuration_generation.h \
    src/testers/tester_one_element_changed_neighborhood.h \
    src/testers/tester_first_improvement_selection.h \
    src/testers/tester_rho_operator.h \
    src/testers/tester_cyclic_operator.h \
    src/testers/tester_best_improvement_selection.h \
    src/testers/tester_sets_index_generator.h \
    src/testers/tester_multi_elements_changed_neighborhood.h \
    src/testers/tester_random_selection.h \
    src/testers/tester_simulated_annealing_decition.h \
    src/testers/tester_best_improvement_tabu_selection.h \
    src/testers/tester_random_permutation_configuration_generation.h \
    src/testers/tester_golfers_permutation_neighborhood.h \
    src/testers/tester_packing_solution.h \
    src/testers/tester_packing_decision_pair.h \
    src/testers/tester_packing_one_element_changed_neighborhood.h \
    src/testers/tester_packing_multi_changes_neighborhood.h \
    src/testers/tester_packing_golfers_permutation_neighborhood.h \
    src/testers/packing_neighborhood_tester.h \
    src/testers/tester_packing_union_neighborhood.h \
    src/testers/tester_conditional_operator.h \
    src/testers/tester_union_operator.h \
    src/testers/tester_multi_sorted_changes_neighborhood.h \
    src/testers/tester_cost_of_solution_golfers.h \
    src/testers/tester_cost_of_solution_golom_rules.h \
    src/testers/tester_cost_of_solution_quaring_square.h \
    src/testers/tester_solver_golfers.h \
    src/testers/tester_solver_golomb_ruler.h \
    src/testers/tester_solver_squaring_square.h \
    src/testers/tester_random_ordered_confgeneration.h \
    src/testers/tester_one_sorted_change_neighborhood.h \
    src/testers/tester_speed_operator.h \
    src/testers/tester_cost_of_solution_nqueens.h \
    src/testers/tester_solver_n_queens.h \
    src/testers/tester_comunication.h \
    src/tools/tools.h \
    src/tools/rand_index_generator.h \
    src/tools/randomizer.h \
    src/tools/tabu_list.h \
    src/tools/long_int.h \
    src/tools/merged_longint.h \
    src/tools/matrix.h \
    src/tools/chronometer.h \
    src/expressions/loop_bound_expression.h \
    src/expressions/iteretion_bound_expression.h \
    src/expressions/boolean_expression.h \
    src/expressions/reached_cost_expression.h \
    src/packing/codable.h \
    src/packing/packers/packer.h \
    src/packing/packers/decision_pair_packer.h \
    src/packing/packers/golfers_single_swap_packer.h \
    src/packing/packers/neighborhood_packer.h \
    src/packing/packers/multi_changes_neighborhood_packer.h \
    src/packing/packers/one_change_neighborhood_packer.h \
    src/packing/packers/solution_packer.h \
    src/packing/factory/factory_packer.h \
    src/packing/factory/factory_solution_packer.h \
    src/packing/factory/factory_decision_pair_packer.h \
    src/packing/factory/factory_one_change_neighborhood_packer.h \
    src/packing/factory/factory_multi_changes_neighborhood_packer.h \
    src/packing/factory/factory_golfers_single_swap_neighborhood_packer.h \
    src/solver/psp.h \
    src/solver/posl_solver.h \
    src/solver/create_solver_strategy.h \
    src/solver/for_golfers_css.h \
    src/solver/for_squaring_square_css.h \
    src/solver/for_golomb_ruler_css.h \
    src/solver/posl_meta_solver.h \
    src/solver/comunicator.h \
    src/solver/for_n_queens_css.h \ 
    src/testers/tester_from_pack_neighborhood.h \
    src/data/dynamic_neighborhood.h \
    src/data/dStrategy/apply_change_behavior.h \
    src/data/dStrategy/single_swap_apply_change_behavior.h \
    src/data/dStrategy/standard_apply_change_behavior.h \
    src/data/dStrategy/sorted_apply_change_behavior.h \
    src/packing/module_uncoder.h \
    src/benchmarks/cost_strategy/golfers_intersections_costs_trategy.h \
    src/benchmarks/cost_strategy/solution_cost_strategy.h \
    src/benchmarks/cost_strategy/golfers_long_int_cost_strategy.h \
    src/benchmarks/cost_strategy/golomb_ruler_distances_cost_strategy.h \
    src/benchmarks/cost_strategy/n_queens_daniel_cost_strategy.h \
    src/benchmarks/cost_strategy/squaring_square_superposition_cost_strategy.h \
    src/testers/tester_tabuselection.h \
    src/expressions/or_expression.h \
    src/expressions/same_cost_iterations_bound_expression.h \
    src/expressions/and_expression.h \
    src/benchmarks/cost_strategy/golfers_3pn_cost_strategy.h \
    src/testers/tester_longint.h \
    src/benchmarks/show_strategy/golfers_default_show_strategy.h \
    src/benchmarks/show_strategy/show_strategy.h \
    src/benchmarks/show_strategy/golomb_ruler_default_show_strategy.h \
    src/benchmarks/show_strategy/n_queens_default_show_strategy.h \
    src/benchmarks/show_strategy/squaring_square_default_show_strategy.h \
    src/benchmarks/relative_cost_strategy/relative_cost_strategy.h \
    src/benchmarks/relative_cost_strategy/golfers_relative_cost_strategy.h \
    src/benchmarks/relative_cost_strategy/squaring_square_relative_cost_strategy.h \
    src/benchmarks/relative_cost_strategy/golomb_ruler_relative_cost_strategy.h \
    src/benchmarks/relative_cost_strategy/nqueens_relative_cost_strategy.h \
    src/tools/t_changes.h \
    src/testers/tester_iteration_golfers.h \
    src/computation/factory_computation_strategy_a000.h \
    src/tools/connection_matrix.h \
    src/computation/factory_computation_strategy_ra000.h \
    src/computation/factory_computation_strategy_sa000.h \
    src/operators/strategy/min_och_sequential_strategy.h \
    src/computation/factory_computation_strategy_b001.h \
    src/solver/strategy/showing_result_strategy.h \
    src/solver/strategy/show_plain_result_strategy.h \
    src/solver/strategy/show_bechmark_result_strategy.h \
    src/solver/strategy/show_to_collect_strategy.h \
    src/tools/hash_map.h \
    src/connections/connectable.h \
    src/tools/posl_tag.h \
    src/solver/posl_name_space.h \
    src/packing/compound_module_uncoder.h \
    src/packing/grouped_sequential_computation_uncoder.h \
    src/packing/grouped_parallel_computation_uncoder.h \
    src/packing/operation_module_uncoder.h \
    src/packing/om_s_uncoder.h \
    src/packing/om_v_uncoder.h \
    src/packing/om_ss_uncoder.h \
    src/packing/om_d_uncoder.h \
    src/packing/operator_uncoder.h \
    src/packing/operator_conditional_uncoder.h \
    src/packing/operator_cyclic_uncoder.h \
    src/packing/operator_flo_uncoder.h \
    src/packing/operator_rho_uncoder.h \
    src/packing/operator_send_uncoder.h \
    src/packing/boolean_expression_uncoder.h \
    src/packing/bool_expression_and_uncoder.h \
    src/packing/bool_expression_or_uncoder.h \
    src/testers/tester_coding_posl.h \
    src/testers/include_testers.h \
    src/tools/tokens_definition.h \
    src/tools/coding_tools.h \
    src/packing/open_channel_uncoder.h \
    src/connections/connector_info.h \
    src/connections/scheduler.h \
    src/connections/connection_operator_broadcasting.h

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
