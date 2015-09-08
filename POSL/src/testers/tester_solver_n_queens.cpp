#include "tester_solver_n_queens.h"

#include "../solver/posl_solver.h"
#include "../solver/for_n_queens_css.h"

Tester_SolverNQueens::Tester_SolverNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverNQueens::test()
{
    shared_ptr<NQueens> bench(make_shared<NQueens>(8));
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    shared_ptr<CreateSolverStrategy> css(make_shared<ForNQueensCSS>(bench));
    vector<shared_ptr<POSL_Solver> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
