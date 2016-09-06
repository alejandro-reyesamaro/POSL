#include "tester_cost_of_solution_nqueens.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionNQueens::Tester_CostOfSolutionNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionNQueens::test()
{
    //vector<int> config5({6, 4, 9, 0, 5, 1, 3, 7, 2, 8}); // costo ?

    shared_ptr<Benchmark> bench(make_shared<NQueens>(10));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::NQueens_10_c0()));
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::NQueens_10_c6());
    int c2 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c2 << endl;

    vector<int> nq_10_c12 = Tester::NQueens_10_c12();
    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), nq_10_c12);
    //int c22 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c22 << endl;

    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::NQueens_10_c11());
    int c3 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c3 << endl;

    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::NQueens_10_c12());
    int c4 = psp->GetBenchmark()->solutionCost(sol);
    //cout << "Cost: " << c4 << endl;

    //bench->InitializeCostData(Tester::NQueens_10_c11());
    int rc1 = 11;
    vector<int> conf_before = Tester::NQueens_10_c11();

    shared_ptr<Solution> sol_before(make_shared<Solution>(bench->Variable_Domain(), conf_before));
    psp->Start(sol_before->get_conf_by_ref());
    int rc2 = psp->GetBenchmark()->relativeSolutionCost(nq_10_c12);
    cout << "Cost: " << rc2 << endl;
    //int rc5 = bench->relativeSolutionCost(config5);
    //rc5 = psp->GetBenchmark()->solutionCost(config5);

    return (c1 == 0 && c2 == 6 && c3 == 11 && c4 == 10 &&
            rc1 == 11 && rc2 == 12)
        ? "CostOfSolution (N-Queens): OK !"
        : "CostOfSolution (N-Queens): fail :/";
}
