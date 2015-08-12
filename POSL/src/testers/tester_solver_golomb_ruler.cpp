#include "tester_solver_golomb_ruler.h"

#include "../solver/posl_solver.h"
#include "../solver/for_golomb_ruler_css.h"

Tester_Solver_GolombRuler::Tester_Solver_GolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_GolombRuler::test()
{
    //Benchmark * bench = new GolombRuler(12,85);
    Benchmark * bench = new GolombRuler(8,34);
    //Benchmark * bench = new GolombRuler(7,25);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);

    FlagComputation * flagC = new FlagSequentialComputation();
    PSP * psp = new PSP(ARGC, ARGV, bench, flagC);

    POSL_Solver * solver = new POSL_Solver(new ForGolombRulerCSS());
    solver->solve(psp);
    return solver->show(psp->GetBenchmark());
}
