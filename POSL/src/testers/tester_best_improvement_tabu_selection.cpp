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
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));    
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_1s());
    //bench->UpdateSolution(sol);
    //PSP> psp(make_shared<PSP(bench);
    psp->UpdateSolution(sol->get_conf_by_ref());
    int initial_cost = psp->GetBenchmark()->solutionCost(sol);


    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_BestImprovementTabuSelection>(bench));

    // cm1 |-> cm2 :
    shared_ptr<Operator> op1(make_shared<SequentialExecOperator>(cm1, cm2));

    // [cm1 |-> cm2] :
    shared_ptr<GroupedComputation> G1(make_shared<GroupedSequentialComputation>(op1));

    // [cm1 |-> cm2] |-> cm3 :
    shared_ptr<Operator> op2(make_shared<SequentialExecOperator>(G1, cm3));

    // [ [cm1 |-> cm2] |-> cm3 ] :
    shared_ptr<GroupedComputation> G2(make_shared<GroupedSequentialComputation>(op2));

    shared_ptr<DecisionPair> pair;
    int cost = 0;

    for(int i = 0; i < 5; i++)
    {
        pair = static_pointer_cast<DecisionPair>(G2->execute(psp, t_seed));
        sol = pair->GetFound();
        cost = psp->GetBenchmark()->solutionCost(sol);
        psp->UpdateSolution(sol->get_conf_by_ref());
        cout << sol->configurationToString() << " - cost: " << cost << endl;
    }
    cout << endl;
    pair = static_pointer_cast<DecisionPair>(G2->execute(psp, sol));
    cout << pair->GetFound()->configurationToString() << endl;

    //string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    //return (cc <= c) ? prefix + " -> OM_BestImprovementSelection: OK !" : "OM_BestImprovementSelection: fail :/";
    return "CI: " + Tools::int2str(initial_cost) + ", OM_BestImprovementTabuSelection: ...";
}
