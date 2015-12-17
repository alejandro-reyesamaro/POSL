#include "tester_solver_golfers.h"
#include "../solver/posl_meta_solver.h"

Tester_Solver_Golfers::Tester_Solver_Golfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_Golfers::test()
{
    shared_ptr<Golfers> g(make_shared<Golfers>(4,4,4));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/POSL_golfers.posl", 10, g));
    posl_ms->solve_sequentially();

    return "Solving Golfers OK!";
}
