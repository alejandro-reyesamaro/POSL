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
    vector<int> config4({4, 8, 3, 8, 2, 7, 1, 6, 0, 5}); // costo 0

    Benchmark * bench = new NQueens(10);
    PSP * psp = new PSP(ARGC, ARGV, bench);
    Solution * sol = new Solution(psp->GetBenchmark()->Domains(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c2 << endl;

    sol = new Solution(psp->GetBenchmark()->Domains(), config3);
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c3 << endl;

    sol = new Solution(psp->GetBenchmark()->Domains(), config4);
    int c4 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c4 << endl;

    return (c1 == 0 && c2 == 6 && c3 == 11 && c4 == 10)
        ? "CostOfSolution (N-Queens): OK !"
        : "CostOfSolution (N-Queens): fail :/";
}
