#include "tester_solver_golfers.h"

#include "../solver/posl_solver.h"
#include "../solver/for_golfers_css.h"
#include "../computation/flag_computation.h"

Tester_Solver_Golfers::Tester_Solver_Golfers(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_Golfers::test()
{
    //Benchmark * bench = new Golfers(5,5,3);
    Benchmark * bench = new Golfers(4,4,2);

    FlagComputation * flagC = new FlagParallelComputation(0, 1);
    PSP * psp = new PSP(ARGC, ARGV, bench, flagC);

    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);

    //POSL_Solver * solver = new POSL_Solver(ARGC, ARGV, bench, new ForGolfersCSS());
    POSL_Solver * solver = new POSL_Solver(psp, new ForGolfersCSS());
    solver->solve();
    return solver->show();
}
