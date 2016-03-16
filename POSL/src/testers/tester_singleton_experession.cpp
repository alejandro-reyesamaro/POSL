#include "tester_singleton_experession.h"
#include "../modules/om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"
#include "../solver/posl_meta_solver.h"

Tester_SingletonExperession::Tester_SingletonExperession(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SingletonExperession::test()
{
    shared_ptr<Benchmark> bench(make_shared<NQueens>(10));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/singleton_expression_test.posl", 10, bench));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> init_sol(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::NQueens_10_c0()));
    psp->UpdateSolution(init_sol->get_conf_by_ref());

    string out_put = posl_ms->test(psp);

    return out_put + " -> OM_SingletonExpression: OK !";
}
