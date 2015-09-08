#include "om_best_improvement_selection.h"

OM_BestImprovementSelection::OM_BestImprovementSelection(shared_ptr<Benchmark> bench)
    : search_strategy(make_shared<NeighborSelectingBestImprovement>(bench->Domains()))
{}

shared_ptr<DecisionPair> OM_BestImprovementSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

string OM_BestImprovementSelection::codeToSend()
{
    return "C3";
}
