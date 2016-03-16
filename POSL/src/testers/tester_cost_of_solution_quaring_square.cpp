#include "tester_cost_of_solution_quaring_square.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"

Tester_CostOfSolutionSquaringSquare::Tester_CostOfSolutionSquaringSquare(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CostOfSolutionSquaringSquare::test()
{
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    shared_ptr<Benchmark> bench(make_shared<SquaringSquare>(10,squares));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    vector<int> config1({0, 6, 0, 6, 7, 4, 7, 0, 0, 6, 6, 4, 7, 7}); // costo 0
    vector<int> config2({2, 0, 6, 1, 5, 7, 0, 2, 1, 6, 8, 2, 0, 4}); // costo 27

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), config1);
    int c1 = psp->GetBenchmark()->solutionCost(sol);

    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), config2);
    int c2 = psp->GetBenchmark()->solutionCost(sol);

    //cout << c1 << " - " << c2 << endl;
    return (c1 == 0 && c2 == 27)
        ? "CostOfSolution (Squaring Square): OK !"
        : "CostOfSolution (Squaring Square): fail :/";
}
