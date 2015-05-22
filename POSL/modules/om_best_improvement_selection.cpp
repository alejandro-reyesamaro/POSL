#include "om_best_improvement_selection.h"
#include "data/strategy_search_in_neighborhood.h"
#include "data/best_improvement_v_search_state.h"

OM_BestImprovementSelection::OM_BestImprovementSelection()
{
}

ComputationData * OM_BestImprovementSelection::execute(Benchmark * bench, ComputationData * input)
{
    StrategySearchInNeighborhood * s = new StrategySearchInNeighborhood(new BestImprovement_VSearchState());
    return s->select(bench, (Neighborhood *)input);
}
