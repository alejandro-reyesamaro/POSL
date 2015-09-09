#include "om_first_improvement_selection.h"

#include <iostream>

OM_FirstImprovementSelection::OM_FirstImprovementSelection(std::shared_ptr<Benchmark> bench)
    : search_strategy(std::make_shared<NeighborSelectingFirstImprovement>(bench->Domains()))
{}

std::shared_ptr<DecisionPair> OM_FirstImprovementSelection::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

std::string OM_FirstImprovementSelection::codeToSend()
{
    return "C2";
}
