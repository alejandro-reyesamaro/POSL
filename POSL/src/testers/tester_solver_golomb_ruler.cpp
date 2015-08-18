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

    PSP * psp = new PSP(ARGC, ARGV, bench);

    CreateSolverStrategy * css = new ForGolombRulerCSS();
    vector<POSL_Solver *> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
