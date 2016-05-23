#include "tester_solver_all_intervals.h"
#include "../solver/posl_meta_solver.h"

Tester_SolverAllIntervals::Tester_SolverAllIntervals(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverAllIntervals::test()
{
    shared_ptr<AllIntervals> ca(make_shared<AllIntervals>(18));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/solver_all_intervals_test.posl", 10, ca));
    posl_ms->solve_sequentially();
    return "Solving All-Intervals OK!";
}
