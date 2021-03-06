#include "tester_solver_golfers.h"
#include "../solver/posl_meta_solver.h"

Tester_Solver_Golfers::Tester_Solver_Golfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_Golfers::test()
{
    shared_ptr<Golfers> g(make_shared<Golfers>(3, 3, 2));
    //shared_ptr<Golfers> g(make_shared<Golfers>(9, 5, 5));
    //shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/experiments201601/POSL_golfers.posl", 10, g));
    //shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/solver_golfers_ring_test.posl", 10, g));
    //shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/solver_golfers_test.posl", 10, g));
    //shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/solver_golfers_dicotomie_test.posl", 10, g));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/solver_golfers_test.posl", 10, g));
    posl_ms->solve_sequentially();
    return "Solving Golfers OK!";
}
