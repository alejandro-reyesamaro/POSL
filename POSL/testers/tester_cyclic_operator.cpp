#include "tester_cyclic_operator.h"

#include "modules/om_fixed_first_configuration.h"
#include "modules/om_random_conf_generation.h"
#include "modules/om_fixed_first_configuration.h"
#include "modules/om_one_element_changed_neighborhood.h"
#include "modules/om_multi_elements_changed_neighborhood.h"
#include "modules/om_best_improvement_selection.h"
#include "modules/om_always_improve_decition.h"
#include "operators/operator.h"
#include "operators/sequential_exec_operator.h"
#include "operators/cyclic_operator.h"
#include "expressions/loop_bound_expression.h"
#include "modules/grouped_computation.h"
#include "modules/grouped_sequential_computation.h"
#include "tools/tools.h"

Tester_CyclicOperator::Tester_CyclicOperator()
{
}

string Tester_CyclicOperator::test()
{
    PSP * psp = new PSP(bench);
    CompoundModule * cm1 = new OM_FixedFirstConfiguration();
    CompoundModule * cm0 = new OM_RandomConfGeneration();
    //CompoundModule * cm2 = new OM_OneElementChangedNeighborhood();
    CompoundModule * cm2 = new OM_MultiElementsChangedNeighborhood();
    CompoundModule * cm3 = new OM_BestImprovementSelection();
    CompoundModule * cm4 = new OM_AlwaysImproveDecition();

    // MAL!!! Seed!!
    Solution * first_solution = (Solution *)cm0->execute(psp, new Seed());
    int first_cost = psp->GetBenchmark()->solutionCost(first_solution);

    // cm2 |-> cm3 :
    Operator * op0 = new SequentialExecOperator(cm2, cm3);

    // [ cm2 |-> cm3 ]:
    GroupedComputation * G23 = new GroupedSequentialComputation(op0);

    // [ cm2 |-> cm3 ] |-> cm4 :
    Operator * op1 = new SequentialExecOperator(G23, cm4);

    // [ [ cm2 |-> cm3 ] |-> cm4] ] :
    GroupedComputation * G234 = new GroupedSequentialComputation(op1);

    // Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } :
    Operator * op2 = new CyclicOperator(G234, new LoopBoundExpression(1000));

    // [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ] :
    GroupedComputation * Gcyc = new GroupedSequentialComputation(op2);

    // cm1 |-> [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ]
    Operator * op3 = new SequentialExecOperator(cm1, Gcyc);

    // [ cm1 |-> [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ] ]
    GroupedComputation * G3 = new GroupedSequentialComputation(op3);

    // MAL!!!!!
    Solution * best_solution = (Solution *)G3->execute(psp, first_solution);


    int cost = psp->GetBenchmark()->solutionCost(best_solution);

    string prefix = "Costs: " + Tools::int2str(first_cost) + " - " + Tools::int2str(cost);
    return (first_cost >= cost) ? prefix + " -> Cyclic Operator: OK !" : "Cyclic Operator: fail :/";
}
