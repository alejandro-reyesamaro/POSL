#include "om_best_improvement_selection.h"

OM_BestImprovementSelection::OM_BestImprovementSelection(std::shared_ptr<Benchmark> bench)
    : search_strategy(std::make_shared<NeighborSelectingBestImprovement>(bench->Domains()))
{}

std::shared_ptr<DecisionPair> OM_BestImprovementSelection::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

std::string OM_BestImprovementSelection::codeToSend()
{
    return "C3";
}
