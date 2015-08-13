#include "for_golfers_css.h"

#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/union_operator.h"
#include "../operators/rho_operator.h"
#include "../operators/cyclic_operator.h"
#include "../operators/conditional_operator.h"

#include "../expressions/loop_bound_expression.h"
#include "../expressions/reached_cost_expression.h"

#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"

ForGolfersCSS::ForGolfersCSS()
{}

CompoundModule * ForGolfersCSS::create()
{
    CompoundModule * cm0 = new OM_RandomConfPermutationByBlocksGeneration();
    CompoundModule * cm1 = new OM_GolfersSingleSwapNeighborhood();

    CompoundModule * cm21 = new OM_BestImprovementTabuSelection();
    CompoundModule * cm22 = new OM_FirstImprovementSelection();
    CompoundModule * cm23 = new OM_BestImprovementSelection();
    CompoundModule * cm24 = new OM_RandomSelection();

    CompoundModule * cm31 = new OM_AlwaysImproveDecision();
    CompoundModule * cm32 = new OM_SimulatedAnnealingDecision();
    CompoundModule * cm4  = new OMS_IterationsCounter();
    CompoundModule * cm5  = new OMS_TimeCounter();

    // cm21 (p) cm22
    Operator * O_rho_21_22 = new RhoOperator(cm21, cm22, 0.5);

    // [ cm21 (p) cm22 ] :
    GroupedComputation * G_rho1 = new GroupedSequentialComputation(O_rho_21_22);

    // cm1 |-> [ cm21 (p) cm22 ] :
    Operator * O_sec_1_Grho1 = new SequentialExecOperator(cm1, G_rho1);
    // cm1 |-> cm2 :
    //Operator * O_sec_1_Grho1 = new SequentialExecOperator(cm1, cm22);

    // [ cm1 |-> [ cm21 (p) cm22 ] ] :
    GroupedComputation * G_sec1 = new GroupedSequentialComputation(O_sec_1_Grho1);

    // cm31 (</ cost > 100 />) cm32
    Operator * O_con_31_32 = new ConditionalOperator(cm32, cm31, new ReachedCostExpression(20));

    // [ cm31 (</ cost > 100 />) cm32 ] :
    GroupedComputation * G_con1 = new GroupedSequentialComputation(O_con_31_32);



    // [ cm1 |-> [ cm21 (p) cm22 ] ] |-> [ cm31 (</ cost > 100 />) cm32 ] :
    //Operator * O_sec_Gsec1_Gcon1 = new SequentialExecOperator(G_sec1, G_con1);
    Operator * O_sec_Gsec1_Gcon1 = new SequentialExecOperator(G_sec1, cm31);

    // [ [ cm1 |-> [ cm21 (p) cm22 ] ] |-> [ cm31 (</ cost > 100 />) cm32 ] ]:
    GroupedComputation * G_sec2 = new GroupedSequentialComputation(O_sec_Gsec1_Gcon1);


    // Adding an iterations counter :
    // <--------------------------------------------------------------------------------->
    Operator * O_sec_Gsec2_4 = new SequentialExecOperator(G_sec2, cm4);
    GroupedComputation * G_sec31 = new GroupedSequentialComputation(O_sec_Gsec2_4);
    // <--------------------------------------------------------------------------------->

    // Adding a time measurer :
    // <--------------------------------------------------------------------------------->
    Operator * O_sec_Gsec31_5 = new SequentialExecOperator(G_sec31, cm5);
    GroupedComputation * G_sec41 = new GroupedSequentialComputation(O_sec_Gsec31_5);
    // <--------------------------------------------------------------------------------->



    // Cyc(500 lopps){ Gsec2 } :
    //Operator * O_cyc1 = new CyclicOperator(G_sec2, new LoopBoundExpression(2000));
    //Operator * O_cyc1 = new CyclicOperator(G_sec31, new ReachedCostExpression(0));
    Operator * O_cyc1 = new CyclicOperator(G_sec41, new LoopBoundExpression(50));

    // [ Cyc(500 lopps){ Gsec2 } ]:
    GroupedComputation * G_cyc1 = new GroupedSequentialComputation(O_cyc1);

    // cm0 |-> [ Cyc(500 lopps){ Gsec2 } ]
    Operator* O_sec_0_Gcyc1 = new SequentialExecOperator(cm0, G_cyc1);

    // [ cm0 |-> [ Cyc(500 lopps){ Gsec2 } ] ]:
    GroupedComputation * G_sec3 = new GroupedSequentialComputation(O_sec_0_Gcyc1);

    // Cyc(10 lopps){ [ cm0 |-> [ Cyc(500 lopps){ Gsec2 } ] ] }:
    Operator * O_cyc2 = new CyclicOperator(G_sec3, new LoopBoundExpression(10));

    // [ Cyc(10 lopps){ [ cm0 |-> [ Cyc(500 lopps){ Gsec2 } ] ] } ]:
    GroupedComputation * G_cyc2 = new GroupedSequentialComputation(O_cyc2);

    return G_cyc2;
}
