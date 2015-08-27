#include "om_best_improvement_selection.h"

OM_BestImprovementSelection::OM_BestImprovementSelection()
    : search_strategy(new NeighborSelectingBestImprovement())
{}

DecisionPair * OM_BestImprovementSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    return search_strategy->select(psp, input);
}

string OM_BestImprovementSelection::codeToSend()
{
    return "C3";
}
