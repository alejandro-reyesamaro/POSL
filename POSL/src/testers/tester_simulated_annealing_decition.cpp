#include "tester_simulated_annealing_decition.h"
#include "../modules/om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_SimulatedAnnealingDecition::Tester_SimulatedAnnealingDecition(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SimulatedAnnealingDecition::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    vector<int> config1(
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

    vector<int> config2(
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

    shared_ptr<Solution> sol1(make_shared<Solution>(psp->GetBenchmark()->Domains(), config1));
    shared_ptr<Solution> sol2(make_shared<Solution>(psp->GetBenchmark()->Domains(), config2));
    //bench->UpdateSolution(sol);
    //PSP> psp(make_shared<PSP(bench);
    psp->UpdateSolution(sol2->GetConfiguration());

    int cost1 = psp->GetBenchmark()->solutionCost(sol1);
    //int cost2 = psp->GetBenchmark()->solutionCost(sol2);

    shared_ptr<CompoundModule> cm1(make_shared<OM_SimulatedAnnealingDecision>());
    shared_ptr<DecisionPair> pair(make_shared<DecisionPair>(sol1, sol2));
    shared_ptr<Solution> decision;

    int final_cost = 0;
    int c = 0, cc = 0;

    for(int i = 0; i < 1000; i++)
    {
        decision = static_pointer_cast<Solution>(cm1->execute(psp, pair));
        final_cost = psp->GetBenchmark()->solutionCost(decision);
        if(cost1 == final_cost) c++; else cc++;
    }

    string prefix = "rate: 1000-" + Tools::int2str(c);
    return (cc > 0) ? prefix + " -> OM_SimulatedAnnealingDecision: OK !" : "OM_SimulatedAnnealingDecision: fail :/";
    //return "c1: " + Tools::int2str(cost1) + ", c2: " + Tools::int2str(cost2) + ", final: " + Tools::int2str(final_cost);
    //return Tools::int2str(c);
}
