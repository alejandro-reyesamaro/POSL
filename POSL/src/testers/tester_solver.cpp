#include "tester_solver.h"

#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decition.h"
#include "../modules/om_simulated_annealing_decition.h"

#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/union_operator.h"
#include "../operators/rho_operator.h"
#include "../operators/cyclic_operator.h"
#include "../operators/conditional_operator.h"

#include "../expressions/loop_bound_expression.h"
#include "../expressions/reached_cost_expression.h"

#include "../tools/tools.h"

Tester_Solver::Tester_Solver(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_Solver::test()
{
    //PSP * psp = new PSP(bench);
    CompoundModule * cm0 = new OM_RandomConfPermutationByBlocksGeneration();
    CompoundModule * cm1 = new OM_GolfersSingleSwapNeighborhood();
    CompoundModule * cm21 = new OM_BestImprovementTabuSelection();
    CompoundModule * cm22 = new OM_FirstImprovementSelection();
    CompoundModule * cm31 = new OM_AlwaysImproveDecition();
    CompoundModule * cm32 = new OM_SimulatedAnnealingDecition();

    // MAL!!! Seed!!
    //Solution * first_solution = (Solution *)cm0->execute(psp, new Seed());
    //cout << first_solution->configurationToString() << endl;



    // cm21 (p) cm22
    Operator * O_rho_21_22 = new RhoOperator(cm21, cm22, 0.5);

    // [ cm21 (p) cm22 ] :
    GroupedComputation * G_rho1 = new GroupedSequentialComputation(O_rho_21_22);

    // cm1 |-> [ cm21 (p) cm22 ] :
    Operator * O_sec_1_Grho1 = new SequentialExecOperator(cm1, G_rho1);

    // [ cm1 |-> [ cm21 (p) cm22 ] ] :
    GroupedComputation * G_sec1 = new GroupedSequentialComputation(O_sec_1_Grho1);

    // cm31 (</ cost > 100 />) cm32
    Operator * O_con_31_32 = new ConditionalOperator(cm31, cm32, new ReachedCostExpression(100));

    // [ cm31 (</ cost > 100 />) cm32 ] :
    GroupedComputation * G_con1 = new GroupedSequentialComputation(O_con_31_32);

    // [ cm1 |-> [ cm21 (p) cm22 ] ] |-> [ cm31 (</ cost > 100 />) cm32 ] :
    Operator * O_sec_Gsec1_Gcon1 = new SequentialExecOperator(G_sec1, G_con1);

    // [ [ cm1 |-> [ cm21 (p) cm22 ] ] |-> [ cm31 (</ cost > 100 />) cm32 ] ]:
    GroupedComputation * G_sec2 = new GroupedSequentialComputation(O_sec_Gsec1_Gcon1);

    // Cyc(500 lopps){ Gsec2 } :
    Operator * O_cyc1 = new CyclicOperator(G_sec2, new LoopBoundExpression(500));

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


    // MAL!!!!!
    Solution * final_solution = (Solution *)G_cyc2->execute(psp, new Seed());
    cout << final_solution->configurationToString() << endl;
    int final_cost = psp->GetBenchmark()->solutionCost(final_solution);
    cout << "Final cost: "<< final_cost << endl;

    cout << endl;

    Solution * best_solution = psp->GetBestSolutionSoFar();
    cout << best_solution->configurationToString() << endl;
    int best_cost = psp->GetBenchmark()->solutionCost(best_solution);
    cout << "Best cost: "<< best_cost << endl;

    // The solver is working so:

    //string solver_code = Gcyc->codeToSend();
    //cout << endl;
    //cout << solver_code << endl;
    //cout << endl;


    //cout << best_solution->configurationToString() << endl;

    //string prefix = "Costs: " + Tools::int2str(first_cost) + " - " + Tools::int2str(cost);
    //return (first_cost >= cost) ? prefix + " -> Cyclic Operator: OK !" : "Cyclic Operator: fail :/";
    return "SOLVER: OK !";
}
