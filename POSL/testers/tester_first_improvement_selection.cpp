#include "tester_first_improvement_selection.h"
#include "modules/om_random_conf_generation.h"
#include "modules/om_one_element_changed_neighborhood.h"
#include "modules/om_first_improvement_selection.h"
#include "operators/operator.h"
#include "operators/sequential_exec_operator.h"
#include "modules/grouped_computation.h"
#include "modules/grouped_sequential_computation.h"
#include "data/decision_pair.h"
#include "computation/tools.h"

Tester_FirstImprovementSelection::Tester_FirstImprovementSelection()
{
}

string Tester_FirstImprovementSelection::test()
{
    PSP * psp = new PSP(bench);
    CompoundModule * cm1 = new OM_RandomConfGeneration();
    CompoundModule * cm2 = new OM_OneElementChangedNeighborhood();
    CompoundModule * cm3 = new OM_FirstImprovementSelection();

    // cm1 |-> cm2 :
    Operator * op1 = new SequentialExecOperator(cm1, cm2);

    // [cm1 |-> cm2] :
    GroupedComputation * G1 = new GroupedSequentialComputation(op1);

    // [cm1 |-> cm2] |-> cm3 :
    Operator * op2 = new SequentialExecOperator(G1, cm3);

    // [ [cm1 |-> cm2] |-> cm3 ] :
    GroupedComputation * G2 = new GroupedSequentialComputation(op2);

    // MAL !!!! poner una solucion donde esta seed
    DecisionPair * pair = (DecisionPair *)G2->execute(psp, new Seed());


    int c = psp->GetBenchmark()->solutionCost(pair->current);
    int cc = psp->GetBenchmark()->solutionCost(pair->found);

    string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    return (cc <= c) ? prefix + " -> OM_FirstImprovementSelection: OK !" : "OM_FirstImprovementSelection: fail :/";
}
