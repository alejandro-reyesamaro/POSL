#include "tester_solver_golomb_ruler.h"

#include "../solver/posl_solver.h"
#include "../solver/for_golomb_ruler_css.h"

Tester_Solver_GolombRuler::Tester_Solver_GolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_GolombRuler::test()
{
    Benchmark * bench = new GolombRuler(12,85);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);

    POSL_Solver * solver = new POSL_Solver(ARGC, ARGV, bench, new ForGolombRulerCSS());
    solver->solve();
    return solver->show();
}
