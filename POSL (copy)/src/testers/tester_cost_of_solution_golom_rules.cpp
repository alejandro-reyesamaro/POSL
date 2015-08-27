#include "tester_cost_of_solution_golom_rules.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionGolomRules::Tester_CostOfSolutionGolomRules(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolomRules::test()
{
    vector<int> config1({0, 1, 4, 10, 12, 17}); // costo 2
    vector<int> config2({0, 1, 4, 10, 18, 23, 25}); // costo 4
    vector<int> config3({0, 1, 4, 9, 15, 22, 32, 34}); // costo 7
    vector<int> config4({0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85}); // costo 20

    Benchmark * bench = new GolombRuler(6, 17);
    PSP * psp = new PSP(ARGC, ARGV, bench);
    Solution * sol = new Solution(psp->GetBenchmark()->Domains(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    bench = new GolombRuler(7, 25);
    psp = new PSP(ARGC, ARGV, bench);
    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    bench = new GolombRuler(8, 34);
    sol = new Solution(psp->GetBenchmark()->Domains(), config3);
    psp = new PSP(ARGC, ARGV, bench);
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 8-34: " << c3 << endl;

    bench = new GolombRuler(12, 85);
    sol = new Solution(psp->GetBenchmark()->Domains(), config4);
    psp = new PSP(ARGC, ARGV, bench);
    int c4 = psp->GetBenchmark()->solutionCost(sol);

    return (c1 == 2 && c2 == 4 && c3 == 7 && c4 == 20)
        ? "CostOfSolution (Golom Ruler): OK !"
        : "CostOfSolution (Golom Ruler): fail :/";
}
