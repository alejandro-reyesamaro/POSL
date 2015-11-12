#include "factory_computation_strategy_b001.h"

#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/cyclic_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"
#include "../expressions/reached_cost_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/same_cost_iterations_bound_expression.h"
#include "../expressions/or_expression.h"
#include "../expressions/and_expression.h"

FactoryComputationStrategy_B001::FactoryComputationStrategy_B001(shared_ptr<Benchmark> _bench,
        shared_ptr<AOM_FirstConfigurationGeneration> first_conf_generation,
        shared_ptr<AOM_NeighborhoodFunction> neighborhood_function,
        shared_ptr<AOM_SelectionFunction> selection_function1,
        shared_ptr<AOM_SelectionFunction> selection_function2,
        shared_ptr<AOM_DecisionFunction> decision_function,
        int loops_main_cycle,
        int loops_restart_cycle)
    : FactoryComputationStrategy(_bench, "B001")
{
    shared_ptr<CompoundModule> cm_iter(make_shared<OMS_IterationsCounter>());
    shared_ptr<CompoundModule> cm_time(make_shared<OMS_TimeCounter>());

    // selection1 |-> decition :
    shared_ptr<Operator> sec1(make_shared<SequentialExecOperator>(selection_function1, decision_function));

    // [ selection1 |-> decition ] :
    shared_ptr<GroupedComputation> G_sec1(make_shared<GroupedSequentialComputation>(sec1));

    // selection2 |-> decition :
    shared_ptr<Operator> sec2(make_shared<SequentialExecOperator>(selection_function2, decision_function));

    // [ selection2 |-> decition ] :
    shared_ptr<GroupedComputation> G_sec2(make_shared<GroupedSequentialComputation>(sec2));

    // [ selection1 |-> decition ] ? [ selection2 |-> decition ] :
    shared_ptr<SameCostIterationsBoundExpression> sc_ex_cond = make_shared<SameCostIterationsBoundExpression>(5);
    shared_ptr<Operator> cond(make_shared<ConditionalOperator>(G_sec1, G_sec2, sc_ex_cond));

    // [ [ selection1 |-> decition ] ? [ selection2 |-> decition ] ] : (SELECTION)
    shared_ptr<GroupedComputation> G_cond(make_shared<GroupedSequentialComputation>(cond));

    // neighborhood |-> [ SELECTION ] :
    shared_ptr<Operator> sec3(make_shared<SequentialExecOperator>(neighborhood_function, G_cond));

    // [ neighborhood |-> [ SELECTION ] ] :
    shared_ptr<GroupedComputation> G_sec3(make_shared<GroupedSequentialComputation>(sec3));

    // Adding an iterations counter :
    // <--------------------------------------------------------------------------------->
    shared_ptr<Operator> sec_itcounter(make_shared<SequentialExecOperator>(G_sec3, cm_iter));
    shared_ptr<GroupedComputation> G_sec_IC(make_shared<GroupedSequentialComputation>(sec_itcounter));
    // <--------------------------------------------------------------------------------->

    // Adding a time measurer :
    // <--------------------------------------------------------------------------------->
    shared_ptr<Operator> sec_timecounter(make_shared<SequentialExecOperator>(G_sec_IC, cm_time));
    shared_ptr<GroupedComputation> G_sec_TC(make_shared<GroupedSequentialComputation>(sec_timecounter));
    // <--------------------------------------------------------------------------------->

    shared_ptr<LoopBoundExpression> loop_b1 = make_shared<LoopBoundExpression>(loops_main_cycle);
    //shared_ptr<SameCostIterationsBoundExpression> sc_ex = make_shared<SameCostIterationsBoundExpression>(25);
    //shared_ptr<OrExpression> ex = make_shared<OrExpression>(loop_b1, sc_ex);
    //shared_ptr<AndExpression> ex = make_shared<AndExpression>(loop_b1, sc_ex);

    // Cyc(n lopps){ G_sec_TC } :
    shared_ptr<Operator> cyc1(make_shared<CyclicOperator>(G_sec_TC, loop_b1));

    // [ Cyc(n lopps){ G_sec_TC } ]:
    shared_ptr<GroupedComputation> G_cyc1(make_shared<GroupedSequentialComputation>(cyc1));

    // first_config |-> [ Cyc(n lopps){ G_sec4 } ]
    shared_ptr<Operator> sec_0(make_shared<SequentialExecOperator>(first_conf_generation, G_cyc1));

    // [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ]:
    shared_ptr<GroupedComputation> G_sec0(make_shared<GroupedSequentialComputation>(sec_0));

    // Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] }:
    shared_ptr<Operator> cyc2(make_shared<CyclicOperator>(G_sec0, make_shared<LoopBoundExpression>(loops_restart_cycle)));

    // [ Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] } ]:
    shared_ptr<GroupedComputation> G_cyc2(make_shared<GroupedSequentialComputation>(cyc2));

    final_module = G_cyc2;
}

shared_ptr<CompoundModule> FactoryComputationStrategy_B001::buildModule(){ return final_module; }
