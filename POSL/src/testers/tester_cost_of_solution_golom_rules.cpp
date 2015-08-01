#include "tester_cost_of_solution_golom_rules.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionGolomRules::Tester_CostOfSolutionGolomRules(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolomRules::test()
{    
    Benchmark * bench = new GolombRuler(6, 17);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config1({0, 1, 4, 10, 12, 17}); // costo 2
    vector<int> config2({0, 1, 3, 10, 12, 17}); // costo 5
    vector<int> config3({0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85});

    sol = new Solution(psp->GetBenchmark()->Domains(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    bench = new GolombRuler(12, 85);
    sol = new Solution(psp->GetBenchmark()->Domains(), config3);
    bench->UpdateSolution(sol);
    psp = new PSP(ARGC, ARGV, bench);
    int c3 = psp->GetBenchmark()->solutionCost(sol);

    cout << c3 << " - " << c2 << endl;
    return (c1 == 2 && c2 == 5)
        ? "CostOfSolution (Golom Ruler): OK !"
        : "CostOfSolution (Golom Ruler): fail :/";
}
