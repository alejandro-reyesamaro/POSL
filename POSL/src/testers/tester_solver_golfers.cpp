#include "tester_solver_golfers.h"

#include "../solver/posl_solver.h"

Tester_Solver_Golfers::Tester_Solver_Golfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_Golfers::test()
{
    /*
    shared_ptr<Golfers> g(make_shared<Golfers>(4,4,4));
    shared_ptr<Benchmark> bench = g;
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<CreateSolverStrategy> css(make_shared<ForGolfersCSS>(g));
    vector<shared_ptr<POSL_Solver>> solvers = css->create();

    solvers[2]->solve(psp);
    return solvers[2]->show();
    //return solvers[2]->show_to_collect();
    */
    return "in process...";
}
