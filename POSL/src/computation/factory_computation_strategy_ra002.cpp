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

FactoryComputationStrategy_RA002::FactoryComputationStrategy_RA002(Benchmark * _bench,
        AOM_FirstConfigurationGeneration * first_conf_generation,
        AOM_NeighborhoodFunction * neighborhood_function_1,
        AOM_NeighborhoodFunction * neighborhood_function_2,
        AOM_SelectionFunction * selection_function_1,
        AOM_SelectionFunction * selection_function_2,
        AOM_DecisionFunction * decision_fucntion_1,
        AOM_DecisionFunction * decision_fucntion_2,
        float prob_op_rho_selection,
        int cost_op_cond_decision,
        int loops_main_cycle,
        int loops_restart_cycle)
    : FactoryComputationStrategy(_bench)
{
    CompoundModule * cm_iter  = new OMS_IterationsCounter();
    CompoundModule * cm_time  = new OMS_TimeCounter();

    // selection1 (p) selection2
    Operator * rho = new RhoOperator(selection_function_1, selection_function_2, prob_op_rho_selection);

    // [ selection1 (p) selection2 ] :
    GroupedComputation * G_rho = new GroupedSequentialComputation(rho);

    // OPEN CHANNEL to receive the selecton from other solvers
    CompoundModule * och_selection = new DecisionPairDataOpenChannel(_bench);
    Operator * min = new MinOperator(G_rho, och_selection);
    GroupedComputation * G_min = new GroupedSequentialComputation(min);
    Operator * cond_1 = new ConditionalOperator(G_rho, G_min, new LoopBoundExpression(4));
    GroupedComputation * G_con1 = new GroupedSequentialComputation(cond_1);

    // neighborhood1 (U) neighborhood1
    Operator * uni = new UnionOperator(neighborhood_function_1, neighborhood_function_2);

    // [ neighborhood1 (U) neighborhood1 ] :
    GroupedComputation * G_uni = new GroupedSequentialComputation(uni);

    // [ neighborhood1 (U) neighborhood1 ] |-> [ selection1 (p) selection2 ] :
    Operator * sec_1 = new SequentialExecOperator(G_uni, G_con1);//G_rho);

    // [ [ neighborhood1 (U) neighborhood1 ] |-> [ selection1 (p) selection2 ] ] :
    GroupedComputation * G_sec1 = new GroupedSequentialComputation(sec_1);

    // decision1 (</ cost />) decision2
    Operator * cond_2 = new ConditionalOperator(decision_fucntion_1, decision_fucntion_2, new ReachedCostExpression(cost_op_cond_decision));

    // [ decision1 (</ cost />) decision2 ] :
    GroupedComputation * G_cond2 = new GroupedSequentialComputation(cond_2);

    // [ neighborhood |-> [ selection1 (p) selection2 ] ] |-> [ decision1 (</ cost />) decision2 ] :
    Operator * sec_2 = new SequentialExecOperator(G_sec1, G_cond2);

    // [ [ neighborhood |-> [ selection1 (p) selection2 ] ] |-> [ decision1 (</ cost />) decision2 ] ]:
    GroupedComputation * G_sec2 = new GroupedSequentialComputation(sec_2);


    // Adding an iterations counter :
    // <--------------------------------------------------------------------------------->
    Operator * sec_3 = new SequentialExecOperator(G_sec2, cm_iter);
    GroupedComputation * G_sec3 = new GroupedSequentialComputation(sec_3);
    // <--------------------------------------------------------------------------------->

    // Adding a time measurer :
    // <--------------------------------------------------------------------------------->
    Operator * sec_4 = new SequentialExecOperator(G_sec3, cm_time);
    GroupedComputation * G_sec4 = new GroupedSequentialComputation(sec_4);
    // <--------------------------------------------------------------------------------->


    // Applying FLO
    Operator * flo = new FlorianOperator(first_conf_generation);
    GroupedComputation * G_flo = new GroupedSequentialComputation(flo);

    // Cyc(n lopps){ G_sec4 } :
    Operator * cyc1 = new CyclicOperator(G_sec4, new LoopBoundExpression(loops_main_cycle));

    // [ Cyc(n lopps){ G_sec4 } ]:
    GroupedComputation * G_cyc1 = new GroupedSequentialComputation(cyc1);

    // first_config |-> [ Cyc(n lopps){ G_sec4 } ]
    Operator* sec_0 = new SequentialExecOperator(G_flo, G_cyc1);

    // [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ]:
    GroupedComputation * G_sec0 = new GroupedSequentialComputation(sec_0);

    // Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] }:
    Operator * cyc2 = new CyclicOperator(G_sec0, new LoopBoundExpression(loops_restart_cycle));

    // [ Cyc(N lopps){ [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ] } ]:
    GroupedComputation * G_cyc2 = new GroupedSequentialComputation(cyc2);

    final_module = G_cyc2;
}

CompoundModule * FactoryComputationStrategy_RA002::buildModule()
{
    return final_module;
}
