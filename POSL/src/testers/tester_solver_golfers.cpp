#include "tester_solver_golfers.h"

#include "../solver/posl_solver.h"
#include "../solver/for_golfers_css.h"
#include "../computation/flag_computation.h"
#include "../solver/for_golfers_css.h"

Tester_Solver_Golfers::Tester_Solver_Golfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_Golfers::test()
{
    shared_ptr<Golfers> g(make_shared<Golfers>(6,6,4));// (4,4,2));
    shared_ptr<Benchmark> bench = g;
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));


    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);

    //POSL_Solver> solver(make_shared<POSL_Solver(ARGC, ARGV, bench, new ForGolfersCSS());
    shared_ptr<CreateSolverStrategy> css(make_shared<ForGolfersCSS>(g));
    vector<shared_ptr<POSL_Solver>> solvers = css->create();

    solvers[2]->solve(psp);
    return solvers[2]->show(psp->GetBenchmark());
    //return solvers[2]->show_to_collect();
}
