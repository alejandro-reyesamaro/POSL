#include "tester_simulated_annealing_decition.h"
#include "../modules/om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tools.h"
#include "../solver/posl_meta_solver.h"

Tester_SimulatedAnnealingDecition::Tester_SimulatedAnnealingDecition(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SimulatedAnnealingDecition::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("../src/testers/test_codes/sa_test.posl", 10, bench));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> init_sol(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_repeted()));
    psp->UpdateSolution(init_sol->get_conf_by_ref());

    int current_cost = psp->GetBenchmark()->solutionCost(init_sol);

    //shared_ptr<CompoundModule> cm1(make_shared<OM_SimulatedAnnealingDecision>(0.7, 0.8, 5));
    //shared_ptr<DecisionPair> pair(make_shared<DecisionPair>(bad_sol, good_sol));
    //shared_ptr<Solution> decision;

    int new_cost = 0;
    int bad_choice = 0, good_choice = 0;
    string out_put;

    for(int i = 0; i < 100; i++)
    {
        //decision = static_pointer_cast<Solution>(cm1->execute(psp, pair));
        out_put = posl_ms->test(psp);
        new_cost = psp->GetBenchmark()->solutionCost(psp->GetBestSolutionSoFar());
        if(current_cost == new_cost) bad_choice++; else good_choice++;
        psp->UpdateSolution(init_sol->get_conf_by_ref());
    }

    string prefix = "rate: 100-" + Tools::int2str(bad_choice);
    return (bad_choice > 0) ? prefix + " -> OM_SimulatedAnnealingDecision: OK !" : "OM_SimulatedAnnealingDecision: fail :/";
    //return "c1: " + Tools::int2str(cost1) + ", c2: " + Tools::int2str(cost2) + ", final: " + Tools::int2str(final_cost);
    //return Tools::int2str(c);
}
