#include "tester_coding_compound_modules.h"

#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
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
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../packing/uncode_compound_module_strategy.h"
#include "../tools/tools.h"

Tester_CodingCompoundModules::Tester_CodingCompoundModules(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_CodingCompoundModules::test()
{
    //PSP * psp = new PSP(bench);
    CompoundModule * cm0 = new OM_RandomConfGeneration();
    CompoundModule * cm1 = new OM_FixedFirstConfiguration();
    CompoundModule * cm2_1 = new OM_OneElementChangedNeighborhood();
    CompoundModule * cm2_2 = new OM_MultiElementsChangedNeighborhood();
    CompoundModule * cm3_1 = new OM_BestImprovementSelection();
    CompoundModule * cm3_2 = new OM_FirstImprovementSelection();
    CompoundModule * cm4_1 = new OM_AlwaysImproveDecition();
    CompoundModule * cm4_2 = new OM_SimulatedAnnealingDecition();

    // MAL!!! Seed!!
    Solution * first_solution = (Solution *)cm0->execute(psp, new Seed());
    //cout << first_solution->configurationToString() << endl;
    int first_cost = psp->GetBenchmark()->solutionCost(first_solution);

    // cm0 |-> cm1 :
    Operator * O_sec_0_1 = new SequentialExecOperator(cm0, cm1);

    // [ cm0 |-> cm1 ]:
    GroupedComputation * G01 = new GroupedSequentialComputation(O_sec_0_1);


    // cm2_1 U cm2_2
    Operator * O_uni_21_22 = new UnionOperator(cm2_1, cm2_2);

    // [ cm2_1 |-> cm2_2 ]:
    GroupedComputation * G02 = new GroupedSequentialComputation(O_uni_21_22);

    // [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] :
    Operator * O_sec_g01_g02 = new SequentialExecOperator(G01, G02);

    // [ [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] ] :
    GroupedComputation * G0102 = new GroupedSequentialComputation(O_sec_g01_g02);

    // cm3_1 (p) cm3_2
    Operator * O_rho_31_32 = new RhoOperator(cm3_1, cm3_2, 0.5);

    // [ cm3_1 |-> cm3_2 ]:
    GroupedComputation * G03 = new GroupedSequentialComputation(O_rho_31_32);

    // [ [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] ] |-> [ cm3_1 |-> cm3_2 ]:
    Operator * O_sec_g0102_g03 = new SequentialExecOperator(G0102, G03);

    // [ [ [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] ] |-> [ cm3_1 |-> cm3_2 ] ] :
    GroupedComputation * G010203 = new GroupedSequentialComputation(O_sec_g0102_g03);

    // cm4_1 (<cond>) cm4_2
    Operator * O_con_41_42 = new ConditionalOperator(cm4_1, cm4_2, new ReachedCostExpression(100));

    // [ cm4_1 (<cond>) cm4_2 ]:
    GroupedComputation * G04 = new GroupedSequentialComputation(O_con_41_42);

    // [ [ [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] ] |-> [ cm3_1 |-> cm3_2 ] ] |-> [ cm4_1 (<cond>) cm4_2 ]:
    Operator * O_sec_g010203_g04 = new SequentialExecOperator(G010203, G04);

    // [ [ [ [ cm0 |-> cm0 ] |-> [ cm2_1 |-> cm2_2 ] ] |-> [ cm3_1 |-> cm3_2 ] ] |-> [ cm4_1 (<cond>) cm4_2 ] ] :
    GroupedComputation * G01020304 = new GroupedSequentialComputation(O_sec_g010203_g04);

    // Cyc(10 lopps){ G01020304 } :
    Operator * cyc = new CyclicOperator(G01020304, new LoopBoundExpression(10));

    // [ Cyc(10 lopps){ G01020304 } ] :
    GroupedComputation * Gcyc = new GroupedSequentialComputation(cyc);

    // MAL!!!!!
    Solution * best_solution = (Solution *)Gcyc->execute(psp, first_solution);
    //cout << best_solution->configurationToString() << endl;

    // The solver is working so:

    string solver_code = Gcyc->codeToSend();
    //cout << endl;
    //cout << solver_code << endl;
    //cout << endl;

    // The coding is working s:
    UncodeCompoundModuleStrategy * uncoder = new UncodeCompoundModuleStrategy();
    CompoundModule * decoded = uncoder->uncode(solver_code);

    best_solution = (Solution *)decoded->execute(psp, first_solution);
    //cout << best_solution->configurationToString() << endl;

    //string prefix = "Costs: " + Tools::int2str(first_cost) + " - " + Tools::int2str(cost);
    //return (first_cost >= cost) ? prefix + " -> Cyclic Operator: OK !" : "Cyclic Operator: fail :/";
    return "Coding modules: OK !";
}
