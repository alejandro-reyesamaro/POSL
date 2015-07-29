#include "tester_simulated_annealing_decition.h"
#include "../modules/om_simulated_annealing_decition.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"

Tester_SimulatedAnnealingDecition::Tester_SimulatedAnnealingDecition(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SimulatedAnnealingDecition::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

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

    Solution * sol1 = new Solution(psp->GetBenchmark()->Domains(), config1);
    Solution * sol2 = new Solution(psp->GetBenchmark()->Domains(), config2);
    //bench->UpdateSolution(sol);
    //PSP * psp = new PSP(bench);
    psp->UpdateSolution(sol2);

    int cost1 = psp->GetBenchmark()->solutionCost(sol1);
    //int cost2 = psp->GetBenchmark()->solutionCost(sol2);

    CompoundModule * cm1 = new OM_SimulatedAnnealingDecition();
    DecisionPair * pair = new DecisionPair(sol1, sol2);
    Solution * decision;

    int final_cost = 0;
    int c = 0, cc = 0;

    for(int i = 0; i < 1000; i++)
    {
        decision = (Solution *)cm1->execute(psp, pair);
        final_cost = psp->GetBenchmark()->solutionCost(decision);
        if(cost1 == final_cost) c++; else cc++;
    }

    string prefix = "rate: 1000-" + Tools::int2str(c);
    return (cc > 0) ? prefix + " -> OM_SimulatedAnnealingDecision: OK !" : "OM_SimulatedAnnealingDecision: fail :/";
    //return "c1: " + Tools::int2str(cost1) + ", c2: " + Tools::int2str(cost2) + ", final: " + Tools::int2str(final_cost);
    //return Tools::int2str(c);
}
