#include "tester_solver_squaring_square.h"

#include "../solver/posl_solver.h"
#include "../solver/for_squaring_square_css.h"

Tester_SolverSquaringSquare::Tester_SolverSquaringSquare(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverSquaringSquare::test()
{
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    shared_ptr<SquaringSquare> ss(make_shared<SquaringSquare>(10,squares));
    shared_ptr<Benchmark> bench = ss;
    //vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
    //SquaringSquare> bench(make_shared<SquaringSquare(110, squares);
    //vector<int> squares({1, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 4, 4, 6, 6, 10, 10});
    //SquaringSquare> bench(make_shared<SquaringSquare(20, squares);
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);

    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    shared_ptr<CreateSolverStrategy> css(make_shared<ForSquaringSquareCSS>(ss));
    vector<shared_ptr<POSL_Solver>> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
