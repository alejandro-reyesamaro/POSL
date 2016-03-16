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

Tester_BestImprovementSelection::Tester_BestImprovementSelection(int argc, char * argv[])
    : Tester(argc, argv)
{
}

string Tester_BestImprovementSelection::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_c4());
    //bench->UpdateSolution(sol);
    //PSP> psp(make_shared<PSP(bench);
    psp->UpdateSolution(sol->get_conf_by_ref());

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_OneElementChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_BestImprovementSelection>(bench));

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

    string prefix = (pair->equals()) ? "NO better solution found" : "new cost: " + Tools::int2str(cc);
    return (cc <= c) ? prefix + " -> OM_BestImprovementSelection: OK !" : "OM_BestImprovementSelection: fail :/";
}
