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
    vector<int> config4({0, 1, 5, 12, 25, 27, 35, 41, 44}); // costo 9
    vector<int> config5({0, 1, 6, 10, 23, 26, 34, 41, 53, 55}); // costo 11
    vector<int> config6({0, 1, 4, 13, 28, 33, 47, 54, 64, 70, 72}); // costo 19
    vector<int> config7({0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85}); // costo 20

    Benchmark * bench = new GolombRuler(6, 17);
    PSP * psp = new PSP(ARGC, ARGV, bench);
    Solution * sol = new Solution(psp->GetBenchmark()->Domains(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 6-17: " << c1 << endl;

    bench = new GolombRuler(7, 25);
    psp = new PSP(ARGC, ARGV, bench);
    sol = new Solution(psp->GetBenchmark()->Domains(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 7-5: " << c2 << endl;

    bench = new GolombRuler(8, 34);
    sol = new Solution(psp->GetBenchmark()->Domains(), config3);
    psp = new PSP(ARGC, ARGV, bench);
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 8-34: " << c3 << endl;

    bench = new GolombRuler(9, 44);
    sol = new Solution(psp->GetBenchmark()->Domains(), config4);
    psp = new PSP(ARGC, ARGV, bench);
    int c4 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 9-44: " << c4 << endl;

    bench = new GolombRuler(10, 55);
    sol = new Solution(psp->GetBenchmark()->Domains(), config5);
    psp = new PSP(ARGC, ARGV, bench);
    int c5 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 10-55: " << c5 << endl;

    bench = new GolombRuler(11, 72);
    sol = new Solution(psp->GetBenchmark()->Domains(), config6);
    psp = new PSP(ARGC, ARGV, bench);
    int c6 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 11-72: " << c6 << endl;

    bench = new GolombRuler(12, 85);
    sol = new Solution(psp->GetBenchmark()->Domains(), config7);
    psp = new PSP(ARGC, ARGV, bench);
    int c7 = psp->GetBenchmark()->solutionCost(sol);
    cout << "Best cost for 12-85: " << c7 << endl;

    return (c1 == 2 && c2 == 4 && c3 == 7 && c4 == 9 && c5 == 11 && c6 == 19 && c7 == 20)
        ? "CostOfSolution (Golom Ruler): OK !"
        : "CostOfSolution (Golom Ruler): fail :/";
}
