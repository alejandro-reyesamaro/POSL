#include "tester_best_improvement_selection.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_BestImprovementSelection::Tester_BestImprovementSelection(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_BestImprovementSelection::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    sol = new Solution(psp->GetBenchmark()->Domains(), config);
    //bench->UpdateSolution(sol);
    //PSP * psp = new PSP(bench);
    psp->UpdateSolution(sol);

    CompoundModule * cm1 = new OM_FixedFirstConfiguration();
    CompoundModule * cm2 = new OM_OneElementChangedNeighborhood();
    CompoundModule * cm3 = new OM_BestImprovementSelection();

    // cm1 |-> cm2 :
    Operator * op1 = new SequentialExecOperator(cm1, cm2);

    // [cm1 |-> cm2] :
    GroupedComputation * G1 = new GroupedSequentialComputation(op1);

    // [cm1 |-> cm2] |-> cm3 :
    Operator * op2 = new SequentialExecOperator(G1, cm3);

    // [ [cm1 |-> cm2] |-> cm3 ] :
    GroupedComputation * G2 = new GroupedSequentialComputation(op2);

    DecisionPair * pair = (DecisionPair *)G2->execute(psp, sol);
    int c = psp->GetBenchmark()->solutionCost(pair->GetCurrent());
    int cc = psp->GetBenchmark()->solutionCost(pair->GetFound());

    string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    return (cc <= c) ? prefix + " -> OM_BestImprovementSelection: OK !" : "OM_BestImprovementSelection: fail :/";
}
