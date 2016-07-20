#include "tester_cost_of_solution_all_intervals.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionAllIntervals::Tester_CostOfSolutionAllIntervals(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionAllIntervals::test()
{
    shared_ptr<Benchmark> benchito(make_shared<AllIntervals>(10));
    shared_ptr<PSP> pspito(make_shared<PSP>(benchito));

    vector<int> all1( { 8, 0, 9, 2, 6, 1, 7, 4, 5, 3 }); // 0
    vector<int> all2( { 8, 1, 6, 2, 9, 0, 7, 4, 5, 3 }); // 14
    vector<int> all3( { 8, 3, 2, 7, 4, 9, 6, 1, 3, 5 }); // 34

    shared_ptr<Solution> sol = make_shared<Solution>(pspito->GetBenchmark()->Variable_Domain(), all1);
    int co1 = pspito->GetBenchmark()->solutionCost(sol);
    //cout << co1 << endl;

    sol = make_shared<Solution>(pspito->GetBenchmark()->Variable_Domain(), all2);
    int co2 = pspito->GetBenchmark()->solutionCost(sol);
    //cout << co2 << endl;

    sol = make_shared<Solution>(pspito->GetBenchmark()->Variable_Domain(), all3);
    int co3 = pspito->GetBenchmark()->solutionCost(sol);
    //cout << co3 << endl;

    return (co1 == 0 && co2 == 14 && co3 == 34)
            ? "CostOfSolution (All-Intervals): OK !"
            : "CostOfSolution (All-Intervals): fail :/";
}
