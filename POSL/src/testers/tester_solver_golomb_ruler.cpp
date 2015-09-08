#include "tester_solver_golomb_ruler.h"

#include "../solver/posl_solver.h"
#include "../solver/for_golomb_ruler_css.h"

Tester_Solver_GolombRuler::Tester_Solver_GolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_Solver_GolombRuler::test()
{
    //GolombRuler * bench(make_shared<GolombRuler(12,85);
    //GolombRuler * bench(make_shared<GolombRuler(8,34);
    shared_ptr<GolombRuler> bench(make_shared<GolombRuler>(7,25));
    shared_ptr<PS> psp(make_shared<PSP>(ARGC, ARGV, bench));

    shared_ptr<CreateSolverStrategy> css(make_shared<ForGolombRulerCSS>(bench));
    vector<vPOSL_Solver> solvers = css->create();

    solvers[0]->solve(psp);
    return solvers[0]->show(psp->GetBenchmark());
}
