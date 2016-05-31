#include "om_daniel_as_restart_processing.h"
#include "../tools/tokens_definition.h"
#include "strategy/all_circular_shift_around_worst_rearrange_strategy.h"
#include "strategy/add_a_constant_rearrange_strategy.h"
#include "strategy/circular_shift_around_bad_rearrange_strategy.h"

#include <iostream>

using namespace std;

OM_DanielASRestartProcessing::OM_DanielASRestartProcessing()
{}

shared_ptr<Solution> OM_DanielASRestartProcessing::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    //reseteable_bench = static_pointer_cast<Reseteable>(psp->GetBenchmark());
    //base_bench = static_pointer_cast<Benchmark>(psp->GetBenchmark());
    vector<int> c = psp->GetBenchmark()->Reset();
    psp->Start(c);
    //shared_ptr<Solution> s (make_shared<Solution> (base_bench->Variable_Domain(), c));
    return make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), c);
}

string OM_DanielASRestartProcessing::codeToSend()
{
    return OM_DANIEL_PROCESSING_TOK;
}

string OM_DanielASRestartProcessing::Tag()
{
    return "Daniel_Rearrangement";
}
