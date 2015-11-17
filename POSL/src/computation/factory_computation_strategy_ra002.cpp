#include "factory_computation_strategy_ra002.h"
#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/union_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/cyclic_operator.h"
#include "../operators/send_data_operator.h"
#include "../operators/min_operator.h"
#include "../operators/florian_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"
#include "../modules/decision_pair_data_open_channel.h"
#include "../expressions/reached_cost_expression.h"
#include "../expressions/loop_bound_expression.h"

FactoryComputationStrategy_RA002::FactoryComputationStrategy_RA002(shared_ptr<Benchmark> _bench,
        shared_ptr<AOM_FirstConfigurationGeneration> first_conf_generation,
        shared_ptr<AOM_NeighborhoodFunction> neighborhood_function_1,
        shared_ptr<AOM_NeighborhoodFunction> neighborhood_function_2,
        shared_ptr<AOM_SelectionFunction> selection_function_1,
        shared_ptr<AOM_SelectionFunction> selection_function_2,
        shared_ptr<AOM_DecisionFunction> decision_fucntion_1,
        shared_ptr<AOM_DecisionFunction> decision_fucntion_2,
        float prob_op_rho_selection,
        int cost_op_cond_decision,
        int loops_main_cycle,
        int loops_restart_cycle)
    : FactoryComputationStrategy(_bench, "A002 (receiver)")
{
    shared_ptr<CompoundModule> cm_iter(make_shared<OMS_IterationsCounter>());
    shared_ptr<CompoundModule> cm_time(make_shared<OMS_TimeCounter>());

    // selection1 (p) selection2
    shared_ptr<Operator> rho(make_shared<RhoOperator>(selection_function_1, selection_function_2, prob_op_rho_selection));

    // [ selection1 (p) selection2 ] :
    shared_ptr<GroupedComputation> G_rho(make_shared<GroupedSequentialComputation>(rho));

    // OPEN CHANNEL to receive the selecton from other solvers
    shared_ptr<CompoundModule> och_selection(make_shared<DecisionPairDataOpenChannel>("Ch1", _bench));
    shared_ptr<Operator> min(make_shared<MinOperator>(G_rho, och_selection));
    shared_ptr<GroupedComputation> G_min(make_shared<GroupedSequentialComputation>(min));
    shared_ptr<Operator> cond_1(make_shared<ConditionalOperator>(G_rho, G_min, make_shared<LoopBoundExpression>(4)));
    shared_ptr<GroupedComputation> G_con1(make_shared<GroupedSequentialComputation>(cond_1));

    // neighborhood1 (U) neighborhood1
    shared_ptr<Operator> uni(make_shared<UnionOperator>(neighborhood_function_1, neighborhood_function_2));

    // [ neighborhood1 (U) neighborhood1 ] :
    shared_ptr<GroupedComputation> G_uni(make_shared<GroupedSequentialComputation>(uni));

    // [ neighborhood1 (U) neighborhood1 ] |-> [ selection1 (p) selection2 ] :
    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(G_uni, G_con1));//G_rho);

    // [ [ neighborhood1 (U) neighborhood1 ] |-> [ selection1 (p) selection2 ] ] :
    shared_ptr<GroupedComputation> G_sec1(make_shared<GroupedSequentialComputation>(sec_1));

    // decision1 (</ cost />) decision2
    shared_ptr<Operator> cond_2(make_shared<ConditionalOperator>(decision_fucntion_1, decision_fucntion_2, make_shared<ReachedCostExpression>(cost_op_cond_decision)));

    // [ decision1 (</ cost />) decision2 ] :
    shared_ptr<GroupedComputation> G_cond2(make_shared<GroupedSequentialComputation>(cond_2));

    // [ neighborhood |-> [ selection1 (p) selection2 ] ] |-> [ decision1 (</ cost />) decision2 ] :
    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(G_sec1, G_cond2));

    // [ [ neighborhood |-> [ selection1 (p) selection2 ] ] |-> [ decision1 (</ cost />) decision2 ] ]:
    shared_ptr<GroupedComputation> G_sec2(make_shared<GroupedSequentialComputation>(sec_2));


    // Adding an iterations counter :
    // <--------------------------------------------------------------------------------->
    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(G_sec2, cm_iter));
    shared_ptr<GroupedComputation> G_sec3(make_shared<GroupedSequentialComputation>(sec_3));
    // <--------------------------------------------------------------------------------->

    // Adding a time measurer :
    // <--------------------------------------------------------------------------------->
    shared_ptr<Operator> sec_4(make_shared<SequentialExecOperator>(G_sec3, cm_time));
    shared_ptr<GroupedComputation> G_sec4(make_shared<GroupedSequentialComputation>(sec_4));
    // <--------------------------------------------------------------------------------->

    // Applying FLO
    shared_ptr<Operator> flo(make_shared<FlorianOperator>(first_conf_generation));
    shared_ptr<GroupedComputation> G_flo(make_shared<GroupedSequentialComputation>(flo));

    // Cyc(n lopps){ G_sec4 } :
    shared_ptr<Operator> cyc1(make_shared<CyclicOperator>(G_sec4, make_shared<LoopBoundExpression>(loops_main_cycle)));

    // [ Cyc(n lopps){ G_sec4 } ]:
    shared_ptr<GroupedComputation> G_cyc1(make_shared<GroupedSequentialComputation>(cyc1));

    // first_config |-> [ Cyc(n lopps){ G_sec4 } ]
    shared_ptr<Operator> sec_0(make_shared<SequentialExecOperator>(G_flo, G_cyc1));

    // [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ]:
    shared_ptr<GroupedComputation> G_sec0(make_shared<GroupedSequentialComputation>(sec_0));

    // Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] }:
    shared_ptr<Operator> cyc2(make_shared<CyclicOperator>(G_sec0, make_shared<LoopBoundExpression>(loops_restart_cycle)));

    // [ Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] } ]:
    shared_ptr<GroupedComputation> G_cyc2(make_shared<GroupedSequentialComputation>(cyc2));

    final_module = G_cyc2;
}

shared_ptr<CompoundModule> FactoryComputationStrategy_RA002::buildModule()
{
    return final_module;
}
