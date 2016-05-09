#include "tester_solver_golomb_ruler.h"
#include "../solver/posl_meta_solver.h"

Tester_Solver_GolombRuler::Tester_Solver_GolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_GolombRuler::test()
{
    //shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(12,85));
    //shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(8,34));
    shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(7,25));
    //shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(6,17));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/solver_golomb_test.posl", 10, gr));
    posl_ms->solve_sequentially();

    return "Solving Golomb-Ruler OK!";
}
