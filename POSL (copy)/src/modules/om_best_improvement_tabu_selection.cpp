#include "om_best_improvement_tabu_selection.h"

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection()
    : search_strategy(new NeighborSelectingBestImprovementTabu())
{}

ComputationData * OM_BestImprovementTabuSelection::execute(PSP *psp, ComputationData * input)
{
    DecisionPair * result = search_strategy->select(psp, (Neighborhood *)input);
    return result;
}

string OM_BestImprovementTabuSelection::codeToSend()
{
    return "C4";
}
