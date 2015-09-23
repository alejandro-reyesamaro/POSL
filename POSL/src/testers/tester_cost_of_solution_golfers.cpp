#include "tester_cost_of_solution_golfers.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../benchmarks/cost_strategy/golfers_intersections_costs_trategy.h"

Tester_CostOfSolutionGolfers::Tester_CostOfSolutionGolfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolfers::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golfers_442_c0());
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golfers_442_c4());
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    bench = make_shared<Golfers>(5,5,3);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golfers_553_c0());
    //bench->UpdateSolution(sol);
    psp = make_shared<PSP>(ARGC, ARGV, bench);
    int c3 = psp->GetBenchmark()->solutionCost(sol);


    //GolfersIntersectionsCostStrategy gi(5,5,3);
    //int co = gi.solutionCost(Tester::Golfers_553_c1());
    //cout << co << endl;

    return (c3 == 0 && c1 == 0 && c2 == 4)
            ? "CostOfSolution (Golfers): OK !"
            : "CostOfSolution (Golfers): fail :/";
}
