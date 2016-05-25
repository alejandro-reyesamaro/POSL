#include "tester_solver_squaring_square.h"
#include "../solver/posl_meta_solver.h"

Tester_SolverSquaringSquare::Tester_SolverSquaringSquare(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_SolverSquaringSquare::test()
{
    /* squaring_square_test.posl */
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    shared_ptr<SquaringSquare> ss(make_shared<SquaringSquare>(10,squares));
    //vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
    //shared_ptr<SquaringSquare> ss(make_shared<SquaringSquare>(110, squares));
    //vector<int> squares({1, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 4, 4, 6, 6, 10, 10});
    //shared_ptr<SquaringSquare> ss(make_shared<SquaringSquare>(20, squares));

    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/squaring_square_test.posl", 10, ss));
    posl_ms->solve_sequentially();
    return "in process...";
}
