#include "tester_solver_squaring_square.h"

#include "../solver/posl_solver.h"
#include "../solver/for_squaring_square_css.h"

Tester_SolverSquaringSquare::Tester_SolverSquaringSquare(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverSquaringSquare::test()
{
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    Benchmark * bench = new SquaringSquare(10,squares);
    //vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
    //Benchmark * bench = new SquaringSquare(110, squares);
    //vector<int> squares({1, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 4, 4, 6, 6, 10, 10});
    //Benchmark * bench = new SquaringSquare(20, squares);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);

    PSP * psp = new PSP(ARGC, ARGV, bench);

    CreateSolverStrategy * css = new ForSquaringSquareCSS();
    vector<POSL_Solver *> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
