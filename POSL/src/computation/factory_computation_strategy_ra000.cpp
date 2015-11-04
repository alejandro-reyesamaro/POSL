#include "factory_computation_strategy_ra000.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/cyclic_operator.h"
#include "../operators/send_data_operator.h"
#include "../operators/min_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"
#include "../modules/decision_pair_data_open_channel.h"
#include "../expressions/reached_cost_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/same_cost_iterations_bound_expression.h"
#include "../expressions/or_expression.h"
#include "../expressions/and_expression.h"

using namespace std;

FactoryComputationStrategy_RA000::FactoryComputationStrategy_RA000(shared_ptr<Benchmark> _bench,
        shared_ptr<AOM_FirstConfigurationGeneration> first_conf_generation,
        shared_ptr<AOM_NeighborhoodFunction> neighborhood_function,
        shared_ptr<AOM_SelectionFunction> selection_function,
        shared_ptr<AOM_DecisionFunction> decision_fucntion,
        int loops_main_cycle,
        int loops_restart_cycle)
    : FactoryComputationStrategy(_bench, "A000(r)")
{
    shared_ptr<CompoundModule> cm_iter(make_shared<OMS_IterationsCounter>());
    shared_ptr<CompoundModule> cm_time(make_shared<OMS_TimeCounter>());

    // OPEN CHANNEL to receive the selecton from other solvers
    shared_ptr<CompoundModule> och_selection(make_shared<DecisionPairDataOpenChannel>(bench));
    shared_ptr<Operator> min(make_shared<MinOperator>(selection_function, och_selection));
    shared_ptr<GroupedComputation>G_min(make_shared<GroupedSequentialComputation>(min));
    shared_ptr<Operator> cond_1(make_shared<ConditionalOperator>(selection_function, G_min, make_shared<LoopBoundExpression>(4)));
    shared_ptr<GroupedComputation> G_con1(make_shared<GroupedSequentialComputation>(cond_1));


    // neighborhood |-> selection :
    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(neighborhood_function, G_con1));

    // [ neighborhood |-> selection ] :
    shared_ptr<GroupedComputation> G_sec1(make_shared<GroupedSequentialComputation>(sec_1));

    // [ neighborhood |-> selection ] |-> decision :
    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(G_sec1, decision_fucntion));

    // [ [ neighborhood |-> selection ] |-> decision ]:
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

    shared_ptr<LoopBoundExpression> loop_b1 = make_shared<LoopBoundExpression>(loops_main_cycle);
    shared_ptr<SameCostIterationsBoundExpression> sc_ex = make_shared<SameCostIterationsBoundExpression>(15);
    //shared_ptr<OrExpression> ex = make_shared<OrExpression>(loop_b1, sc_ex);
    shared_ptr<AndExpression> ex = make_shared<AndExpression>(loop_b1, sc_ex);

    // Cyc(n lopps){ G_sec4 } :
    shared_ptr<Operator> cyc1(make_shared<CyclicOperator>(G_sec4, ex));

    // [ Cyc(n lopps){ G_sec4 } ]:
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

shared_ptr<CompoundModule> FactoryComputationStrategy_RA000::buildModule()
{
    return final_module;
}