#include "tester_solver_n_queens.h"

#include "../solver/posl_solver.h"
#include "../solver/for_n_queens_css.h"

Tester_SolverNQueens::Tester_SolverNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverNQueens::test()
{
    NQueens * bench = new NQueens(8);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    CreateSolverStrategy * css = new ForNQueensCSS(bench);
    vector<POSL_Solver *> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
