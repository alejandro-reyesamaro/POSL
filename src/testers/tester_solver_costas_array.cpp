#include "tester_solver_costas_array.h"
#include "../solver/posl_meta_solver.h"

Tester_SolverCostasArray::Tester_SolverCostasArray(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverCostasArray::test()
{
    shared_ptr<CostasArray> ca(make_shared<CostasArray>(15));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/solver_costas_test.posl", 10, ca));
    posl_ms->solve_sequentially();
    return "Solving Costas OK!";
}
