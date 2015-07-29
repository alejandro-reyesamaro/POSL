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
    vector<int> config2({0, 1, 3, 10, 12, 17}); // costo mmmm

    sol = new Solution(psp->GetBenchmark()->Domains(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    cout << c1 << " - " << c2 << endl;
    return (c1 == 0 && c2 == 27)
        ? "CostOfSolution (Golom Ruler): OK !"
        : "CostOfSolution (Golom Ruler): fail :/";
}
