#include "tester_solver_n_queens.h"
#include "../solver/posl_meta_solver.h"

Tester_SolverNQueens::Tester_SolverNQueens(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverNQueens::test()
{
    shared_ptr<NQueens> nq(make_shared<NQueens>(300));
    //shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/experiments201601/nq.posl", 10, nq));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/solver_nqueens_test.posl", 10, nq));
    posl_ms->solve_sequentially();

    return "Solving N-Queens OK!";
}
