#include "tester_best_improvement_tabu_selection.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_BestImprovementTabuSelection::Tester_BestImprovementTabuSelection(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_BestImprovementTabuSelection::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1
    });

    sol = new Solution(psp->GetBenchmark()->Domains(), config);
    //bench->UpdateSolution(sol);
    //PSP * psp = new PSP(bench);
    psp->UpdateSolution(sol);
    int initial_cost = psp->GetBenchmark()->solutionCost(sol);


    CompoundModule * cm1 = new OM_FixedFirstConfiguration(bench);
    CompoundModule * cm2 = new OM_MultiElementsChangedNeighborhood(bench);
    CompoundModule * cm3 = new OM_BestImprovementTabuSelection(bench);

    // cm1 |-> cm2 :
    Operator * op1 = new SequentialExecOperator(cm1, cm2);

    // [cm1 |-> cm2] :
    GroupedComputation * G1 = new GroupedSequentialComputation(op1);

    // [cm1 |-> cm2] |-> cm3 :
    Operator * op2 = new SequentialExecOperator(G1, cm3);

    // [ [cm1 |-> cm2] |-> cm3 ] :
    GroupedComputation * G2 = new GroupedSequentialComputation(op2);

    DecisionPair * pair;
    int cost = 0;

    for(int i = 0; i < 5; i++)
    {
        pair = (DecisionPair *)G2->execute(psp, sol);
        sol = pair->GetFound();
        cost = psp->GetBenchmark()->solutionCost(sol);
        psp->UpdateSolution(sol);
        cout << sol->configurationToString() << " - cost: " << cost << endl;
    }
    cout << endl;
    pair = (DecisionPair *)G2->execute(psp, sol);
    cout << pair->GetFound()->configurationToString() << endl;

    //string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    //return (cc <= c) ? prefix + " -> OM_BestImprovementSelection: OK !" : "OM_BestImprovementSelection: fail :/";
    return "CI: " + Tools::int2str(initial_cost) + ", OM_BestImprovementTabuSelection: ...";
}
