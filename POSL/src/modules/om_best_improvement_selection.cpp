#include "om_best_improvement_selection.h"
#include "../data/dStrategy/strategy_search_in_neighborhood.h"
#include "../data/dStrategy/best_improvement_v_search_state.h"

OM_BestImprovementSelection::OM_BestImprovementSelection()
{
}

ComputationData * OM_BestImprovementSelection::execute(PSP *psp, ComputationData * input)
{
    StrategySearchInNeighborhood * s = new StrategySearchInNeighborhood(new BestImprovement_VSearchState());
    return s->select(psp, (Neighborhood *)input);
}

string OM_BestImprovementSelection::codeToSend()
{
    return "C3";
}
