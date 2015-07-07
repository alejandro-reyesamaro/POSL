#include "om_best_improvement_tabu_selection.h"
#include "data/strategy_search_in_neighborhood.h"
#include "data/best_improvement_tabu_v_search_state.h"

#define N_TABULIST 5

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection() : tabu_list(new TabuList(N_TABULIST))
{}

ComputationData * OM_BestImprovementTabuSelection::execute(PSP *psp, ComputationData * input)
{
    tabu_list->push(psp->GetCurrentSolution());
    StrategySearchInNeighborhood * s = new StrategySearchInNeighborhood(new BestImprovementTabu_VSearchState(tabu_list));
    return s->select(psp, (Neighborhood *)input);
}
