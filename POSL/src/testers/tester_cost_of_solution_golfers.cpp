#include "tester_cost_of_solution_golfers.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../benchmarks/cost_strategy/golfers_intersections_costs_trategy.h"

Tester_CostOfSolutionGolfers::Tester_CostOfSolutionGolfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolfers::test()
{

    shared_ptr<Benchmark> bench442(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol442(make_shared<Solution>(bench442->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp442(make_shared<PSP>(ARGC, ARGV, bench442));

    sol442 = make_shared<Solution>(psp442->GetBenchmark()->Domains(), Tester::Golfers_442_c0());
    int c1 = psp442->GetBenchmark()->solutionCost(sol442);

    sol442 = make_shared<Solution>(psp442->GetBenchmark()->Domains(), Tester::Golfers_442_c4());
    int c2 = psp442->GetBenchmark()->solutionCost(sol442);

    shared_ptr<Benchmark> bench553(make_shared<Golfers>(5,5,4));
    shared_ptr<Solution> sol553(make_shared<Solution>(bench553->Domains(), Tester::Golfers_554_c0()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp553(make_shared<PSP>(ARGC, ARGV, bench553));
    int c3 = psp553->GetBenchmark()->solutionCost(sol553);

    shared_ptr<Benchmark> bench662(make_shared<Golfers>(6,6,2));
    shared_ptr<Solution> sol662(make_shared<Solution>(bench662->Domains(), Tester::Golfers_662_c0()));
    shared_ptr<PSP> psp662(make_shared<PSP>(ARGC, ARGV, bench662));
    int c4 = psp662->GetBenchmark()->solutionCost(sol662);


    //GolfersIntersectionsCostStrategy gi(5,5,3);
    //int co = gi.solutionCost(Tester::Golfers_553_c1());
    //cout << co << endl;

    return (c4 == 0 && c1 == 0 && c2 == 4 && c3 == 0)
            ? "CostOfSolution (Golfers): OK !"
            : "CostOfSolution (Golfers): fail :/";
}
