#include "tester_cost_of_solution_golfers.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionGolfers::Tester_CostOfSolutionGolfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolfers::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    vector<int> config2(
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

    vector<int> config3(
    {
        1,   2,  3,  4,  5,
        6,   7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25,

        1, 6, 11, 16, 21,
        2, 7, 12, 17, 22,
        3, 8, 13, 18, 23,
        4, 9, 14, 19, 24,
        5, 10, 15, 20, 25,

        5, 9, 13, 17, 21,
        10, 14, 18, 22, 1,
        15, 19, 23, 6, 2,
        20, 24, 11, 7, 3,
        25, 4, 8, 12, 16
    });

    sol = new Solution(psp->GetBenchmark()->Domains(), config);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    bench = new Golfers(5,5,3);
    sol = new Solution(psp->GetBenchmark()->Domains(), config3);
    bench->UpdateSolution(sol);
    psp = new PSP(ARGC, ARGV, bench);
    int c3 = psp->GetBenchmark()->solutionCost(sol);

    return (c3 == 0 && c1 == 0 && c2 == 4)
            ? "CostOfSolution (Golfers): OK !"
            : "CostOfSolution (Golfers): fail :/";
}
