#include "tester_cost_of_solution_nqueens.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionNQueens::Tester_CostOfSolutionNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionNQueens::test()
{
    vector<int> config1({4, 9, 3, 8, 2, 7, 1, 6, 0, 5}); // costo 0
    vector<int> config2({4, 3, 9, 8, 2, 7, 1, 6, 0, 5}); // costo 6
    vector<int> config3({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // costo 11
    vector<int> config4({4, 8, 3, 8, 2, 7, 1, 6, 0, 5}); // costo 10

    vector<int> config5({6, 4, 9, 0, 5, 1, 3, 7, 2, 8}); // costo ?

    shared_ptr<Benchmark> bench(make_shared<NQueens>(10));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config1));
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c2 << endl;

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), config3);
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c3 << endl;

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), config4);
    int c4 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c4 << endl;

    //bench->InitializeCostData(config2);
    int rc1 = 11;
    //bench->UpdateSolution(config3);
    int rc2 = bench->relativeSolutionCost(config4);
    int rc5 = bench->relativeSolutionCost(config5);
    rc5 = psp->GetBenchmark()->solutionCost(config5);

    return (c1 == 0 && c2 == 6 && c3 == 11 && c4 == 10 &&
            rc1 == 11 && rc2 == 10)
        ? "CostOfSolution (N-Queens): OK !"
        : "CostOfSolution (N-Queens): fail :/";
}
