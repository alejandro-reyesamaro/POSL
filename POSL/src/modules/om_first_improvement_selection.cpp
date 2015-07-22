#include "om_first_improvement_selection.h"
#include "../data/dStrategy/strategy_search_in_neighborhood.h"
#include "../data/dStrategy/first_improvement_v_search_state.h"

OM_FirstImprovementSelection::OM_FirstImprovementSelection()
{
}

ComputationData * OM_FirstImprovementSelection::execute(PSP *psp, ComputationData * input)
{
    StrategySearchInNeighborhood * s = new StrategySearchInNeighborhood(new FirstImprovement_VSearchState());
    return s->select(psp, (Neighborhood *)input);
}
