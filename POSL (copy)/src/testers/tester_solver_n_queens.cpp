#include "tester_solver_n_queens.h"

#include "../solver/posl_solver.h"
#include "../solver/for_n_queens_css.h"

Tester_SolverNQueens::Tester_SolverNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverNQueens::test()
{
    //Benchmark * bench = new Golfers(5,5,3);
    Benchmark * bench = new NQueens(8);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    //POSL_Solver * solver = new POSL_Solver(ARGC, ARGV, bench, new ForGolfersCSS());
    CreateSolverStrategy * css = new ForNQueensCSS();
    vector<POSL_Solver *> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
