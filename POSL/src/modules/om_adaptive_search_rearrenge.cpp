#include "om_adaptive_search_rearrenge.h"
#include "../tools/tokens_definition.h"
#include "strategy/all_circular_shift_around_worst_rearrange_strategy.h"
#include "strategy/add_a_constant_rearrange_strategy.h"
#include "strategy/circular_shift_around_bad_rearrange_strategy.h"

#include <iostream>

using namespace std;

OM_AdaptiveSearchRearrenge::OM_AdaptiveSearchRearrenge(shared_ptr<Benchmark> bench)
    : all_circualr_shift_str(make_shared<AllCircularShiftAroundWorstRearrangeStrategy>(bench->Domains().size())),
      circualr_shift_str(make_shared<CircularShiftAroundBadRearrangeStrategy>(bench->Domains().size())),
      add_const_str(make_shared<AddAConstantRearrangeStrategy>()),
      three_stpes_solutions(3)
{}

shared_ptr<Solution> OM_AdaptiveSearchRearrenge::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    three_stpes_solutions[0] = all_circualr_shift_str->rearrangement(psp, input->get_conf_by_ref());
    three_stpes_solutions[1] = circualr_shift_str->rearrangement(psp, input->get_conf_by_ref());
    three_stpes_solutions[2] = add_const_str->rearrangement(psp, input->get_conf_by_ref());

    cost_1 = psp->GetBenchmark()->solutionCost(three_stpes_solutions[0]);
    cost_2 = psp->GetBenchmark()->solutionCost(three_stpes_solutions[1]);
    cost_3 = psp->GetBenchmark()->solutionCost(three_stpes_solutions[2]);

    //cout << cost_1 << " - " << cost_2 << " - " << cost_3 << endl;

    int best_cost = min(cost_1, cost_2);
    int ws = (cost_1 < cost_2) ? 0 : 1;
    ws     = (best_cost < cost_3) ? ws : 2;

    psp->Start(three_stpes_solutions[ws]->get_conf_by_ref());
    return three_stpes_solutions[ws];
}

string OM_AdaptiveSearchRearrenge::codeToSend()
{
    return OM_AS_REARRANGEMENT_TOK;
}

string OM_AdaptiveSearchRearrenge::Tag()
{
    return "Adaptive_Search_Rearrangement";
}
