#include "tester_cost_on_variable_golomb_ruler.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOnVariableGolombRuler::Tester_CostOnVariableGolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOnVariableGolombRuler::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6, 17));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    vector<int> gr ({0, 1, 4, 8, 12, 17});
    //shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), gr));
    psp->UpdateSolution(gr);
    int c = psp->GetBenchmark()->costOnVariable(3);
    //cout << "Cost: " << c << endl;

    return (c == 1)
        ? "CostOnVariable (Golom Ruler): OK !"
        : "CostOnVariable (Golom Ruler): fail :/";
}
