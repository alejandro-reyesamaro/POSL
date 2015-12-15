#include "tester_cost_of_solution_costas_array.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionCostasArray::Tester_CostOfSolutionCostasArray(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionCostasArray::test()
{
    shared_ptr<Benchmark> bench(make_shared<CostasArray>(6));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Costas_6_c0());
    int c1 = psp->GetBenchmark()->solutionCost(sol);
    cout << c1 << endl;

    return (c1 == 0)
            ? "CostOfSolution (Costas): OK !"
            : "CostOfSolution (Costas): fail :/";
}
