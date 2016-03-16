#include "tester_cost_of_solution_costas_array.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionCostasArray::Tester_CostOfSolutionCostasArray(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionCostasArray::test()
{
    shared_ptr<Benchmark> benchito(make_shared<CostasArray>(6));
    shared_ptr<Solution> solita(make_shared<Solution>(benchito->Domains()));
    shared_ptr<PSP> pspito(make_shared<PSP>(benchito));

    shared_ptr<Benchmark> bench16(make_shared<CostasArray>(16));
    shared_ptr<Solution> sol16(make_shared<Solution>(bench16->Domains()));
    shared_ptr<PSP> psp16(make_shared<PSP>(bench16));

    shared_ptr<Benchmark> bench(make_shared<CostasArray>(18));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //vector<int> c1( { 2, 4, 3, 13, 14, 12, 6, 9, 7, 8, 5, 11, 10, 15, 1 }); // 3956
    //vector<int> c2( { 2, 7, 4, 3, 13, 14, 12, 6, 9, 8, 5, 11, 10, 15, 1 }); //2909
    //vector<int> c3( { 2, 11, 15, 5, 6, 1, 3, 8, 7, 14, 12, 4, 10, 13, 9 }); //625

    solita = make_shared<Solution>(pspito->GetBenchmark()->Domains(), Tester::Costas_6_c0());
    int co1 = pspito->GetBenchmark()->solutionCost(solita);
    cout << co1 << endl;

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Costas_18_c0());
    int co2 = psp->GetBenchmark()->solutionCost(sol);
    cout << co2 << endl;

    sol16 = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Costas_16_c0());
    int co3 = psp16->GetBenchmark()->solutionCost(sol16);
    cout << co3 << endl;

    //sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), c3);
    //int co4 = psp->GetBenchmark()->solutionCost(sol);
    //cout << co4 << endl;

    return (co1 == 0 && co2 == 0 && co3 == 0)
            ? "CostOfSolution (Costas): OK !"
            : "CostOfSolution (Costas): fail :/";
}
