#include "tester_solver_subsum.h"
#include "../solver/posl_meta_solver.h"
#include "../tools/tools.h"
#include "../tools/golomb_tools.h"

Tester_SolverSubsum::Tester_SolverSubsum(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverSubsum::test()
{
    int order = 20;
    int length = 283;
    int max_sum = GolombTools::max_posible_distances(order, length);
    vector<int> values(Tools::generateMonotony(1,max_sum));
    shared_ptr<Subsum> gr(make_shared<Subsum>(values, length, order-1));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/solver_subsum_test.posl", 10, gr));
    posl_ms->solve_sequentially();

    return "Solving Subsum OK!";
}
