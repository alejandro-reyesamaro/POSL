#include "tester_cost_of_solution.h"
#include "data/solution.h"
#include "benchmarks/benchmark.h"
#include "benchmarks/golfers.h"

Tester_CostOfSolution::Tester_CostOfSolution()
{
}

string Tester_CostOfSolution::test(){

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

    Solution * sol = new Solution(bench->GetSolution()->domains, config);
    int c1 = bench->solutionCost(sol);

    sol->configuration = config2;
    int c2 = bench->solutionCost(sol);

    return (c1 == 0 && c2 == 4) ? "CostOfSolution: OK !" : "CostOfSolution: fail :/";
}
