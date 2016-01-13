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
      add_const_str(make_shared<AddAConstantRearrangeStrategy>())
{}

shared_ptr<Solution> OM_AdaptiveSearchRearrenge::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    sol_1 = all_circualr_shift_str->rearrangement(input->GetConfiguration(), psp->GetBenchmark());
    sol_2 = circualr_shift_str->rearrangement(input->GetConfiguration(), psp->GetBenchmark());
    sol_3 = add_const_str->rearrangement(input->GetConfiguration(), psp->GetBenchmark());

    cost_1 = psp->GetBenchmark()->solutionCost(sol_1);
    cost_2 = psp->GetBenchmark()->solutionCost(sol_1);
    cost_3 = psp->GetBenchmark()->solutionCost(sol_3);

    int best_cost = min(cost_1, cost_2);
    int ws = (cost_1 < cost_2) ? 1 : 2;
    ws     = (best_cost < cost_3) ? ws : 3;

    switch (ws)
    {
        case 1: return sol_1; break;
        case 2: return sol_2; break;
        default: return sol_3;
    }
}

string OM_AdaptiveSearchRearrenge::codeToSend()
{
    return OM_AS_REARRANGEMENT_TOK;
}

string OM_AdaptiveSearchRearrenge::Tag()
{
    return "Adaptive_Search_Rearrangement";
}
