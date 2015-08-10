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
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);

    FlagComputation * flagC = new FlagSequentialComputation();
    PSP * psp = new PSP(ARGC, ARGV, bench, flagC);

    POSL_Solver * solver = new POSL_Solver(new ForSquaringSquareCSS());
    solver->solve(psp);
    return solver->show(psp->GetBenchmark());
}
