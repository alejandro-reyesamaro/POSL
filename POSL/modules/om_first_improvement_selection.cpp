#include "om_first_improvement_selection.h"
#include "data/strategy_search_in_neighborhood.h"
#include "data/best_improvement_v_search_state.h"

OM_FirstImprovementSelection::OM_FirstImprovementSelection()
{
}

ComputationData * OM_FirstImprovementSelection::execute(Benchmark * bench, ComputationData * input)
{
    StrategySearchInNeighborhood * s = new StrategySearchInNeighborhood(new BestImprovement_VSearchState()---); //CAMBIAR!!!
    return s->select(bench, (Neighborhood *)input);
}
