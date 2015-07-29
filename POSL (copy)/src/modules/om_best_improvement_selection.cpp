#include "om_best_improvement_selection.h"

OM_BestImprovementSelection::OM_BestImprovementSelection()
    : search_strategy(new NeighborSelectingBestImprovement())
{}

ComputationData * OM_BestImprovementSelection::execute(PSP *psp, ComputationData * input)
{
    return search_strategy->select(psp, (Neighborhood *)input);
}

string OM_BestImprovementSelection::codeToSend()
{
    return "C3";
}
