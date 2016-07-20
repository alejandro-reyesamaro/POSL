#include "tester_k_best_improvement_selection.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_k_best_improvement_selection.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_KBestImprovementSelection::Tester_KBestImprovementSelection(int argc, char * argv[])
    : Tester(argc, argv)
{
}

string Tester_KBestImprovementSelection::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_c14());
    //bench->UpdateSolution(sol);
    //PSP> psp(make_shared<PSP(bench);
    bench->SetDefaultConfiguration(sol->get_conf_by_ref());

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_GolfersSingleSwapNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_KBestImprovementSelection>(bench,1));

    // cm1 |-> cm2 :
    shared_ptr<Operator> op1(make_shared<SequentialExecOperator>(cm1, cm2));

    // [cm1 |-> cm2] :
    shared_ptr<GroupedComputation> G1(make_shared<GroupedSequentialComputation>(op1));

    // [cm1 |-> cm2] |-> cm3 :
    shared_ptr<Operator> op2(make_shared<SequentialExecOperator>(G1, cm3));

    // [ [cm1 |-> cm2] |-> cm3 ] :
    shared_ptr<GroupedComputation> G2(make_shared<GroupedSequentialComputation>(op2));

    shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(G2->execute(psp, t_seed));
    int c = psp->GetBenchmark()->solutionCost(pair->GetCurrent());
    int cc = psp->GetBenchmark()->solutionCost(pair->GetFound());

    //cout << "before: " << c << endl;
    //cout << "after: " << cc << endl;

    string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    return (cc <= c) ? prefix + " -> OM_KBestImprovementSelection: OK !" : "OM_KBestImprovementSelection: fail :/";
}
