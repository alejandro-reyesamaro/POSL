#include "tester_solver_golomb_ruler.h"
#include "../solver/posl_meta_solver.h"

Tester_Solver_GolombRuler::Tester_Solver_GolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_GolombRuler::test()
{
    int order = 8;      //  6,  7,  8, 10, 12
    int length = 34;    // 17, 25, 34, 55, 85
    shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(order, length));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/solver_golomb_test.posl", 10, gr));
    posl_ms->solve_sequentially();

    return "Solving Golomb-Ruler OK!";
}
