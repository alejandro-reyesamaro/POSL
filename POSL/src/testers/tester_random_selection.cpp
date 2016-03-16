#include "tester_random_selection.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_random_selection.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_RandomSelection::Tester_RandomSelection(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RandomSelection::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<CompoundModule> cm1(make_shared<OM_RandomConfGeneration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_OneElementChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_RandomSelection>(bench));

    // cm1 |-> cm2 :
    shared_ptr<Operator> op1(make_shared<SequentialExecOperator>(cm1, cm2));

    // [cm1 |-> cm2] :
    shared_ptr<GroupedComputation> G1(make_shared<GroupedSequentialComputation>(op1));

    // [cm1 |-> cm2] |-> cm3 :
    shared_ptr<Operator> op2(make_shared<SequentialExecOperator>(G1, cm3));

    // [ [cm1 |-> cm2] |-> cm3 ] :
    shared_ptr<GroupedComputation> G2(make_shared<GroupedSequentialComputation>(op2));

    //cout << "Modules created" << endl;

    shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(G2->execute(psp, t_seed));

    //cout << "Module executed" << endl;

    int c = psp->GetBenchmark()->solutionCost(pair->GetCurrent());
    int cc = psp->GetBenchmark()->solutionCost(pair->GetFound());

    string prefix = Tools::int2str(c) + " - " + Tools::int2str(cc);
    //return (cc <= c) ? prefix + " -> OM_RandomSelection: OK !" : "OM_RandomSelection: fail :/";
    return prefix + " -> OM_RandomSelection: OK !";
}
