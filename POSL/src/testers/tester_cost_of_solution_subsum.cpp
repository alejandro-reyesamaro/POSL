#include "tester_cost_of_solution_subsum.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionSubsum::Tester_CostOfSolutionSubsum(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionSubsum::test()
{
    vector<int> conf({1, 2, 3, 4, 5, 6, 7});
    shared_ptr<Benchmark> bench(make_shared<Subsum>(conf, 17, 5));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), conf));
    int c1 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost (2): " << c1 << endl;

    conf[0] = 7;
    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), conf);
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost (4): " << c2 << endl;

    conf[0] = 1;
    conf[4] = 7;
    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), conf);
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost (0): " << c3 << endl;

    return (c1 == 2 && c2 == 4 && c3 == 0)
        ? "CostOfSolution (Subsum): OK !"
        : "CostOfSolution (Subsum): fail :/";
}
