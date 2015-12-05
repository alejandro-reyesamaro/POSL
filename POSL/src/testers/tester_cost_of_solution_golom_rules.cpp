#include "tester_cost_of_solution_golom_rules.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionGolomRules::Tester_CostOfSolutionGolomRules(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionGolomRules::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6, 17));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_6_17_c2()));
    int c1 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 6-17: " << c1 << endl;

    bench = make_shared<GolombRuler>(7, 25);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_7_25_c4());
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 7-5: " << c2 << endl;

    bench = make_shared<GolombRuler>(8, 34);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_8_34_c7());
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 8-34: " << c3 << endl;

    bench = make_shared<GolombRuler>(9, 44);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_9_44_c9());
    int c4 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 9-44: " << c4 << endl;

    bench = make_shared<GolombRuler>(10, 55);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_10_55_c11());
    int c5 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 10-55: " << c5 << endl;

    bench = make_shared<GolombRuler>(11, 72);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_11_72_c19());
    int c6 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 11-72: " << c6 << endl;

    bench = make_shared<GolombRuler>(12, 85);
    psp = make_shared<PSP>(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golomb_12_85_c19());
    int c7 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Best cost for 12-85: " << c7 << endl;

    return (c1 == 2 && c2 == 4 && c3 == 7 && c4 == 9 && c5 == 11 && c6 == 19 && c7 == 20)
        ? "CostOfSolution (Golom Ruler): OK !"
        : "CostOfSolution (Golom Ruler): fail :/";
}
