#include "neighbor_selecting_best_improvement_tabu.h"

#define TABU_SIZE 10

NeighborSelectingBestImprovementTabu::NeighborSelectingBestImprovementTabu(vector<Domain> domains)
    : rPair(new DecisionPair(new Solution(domains), new Solution(domains))),
      tabu_list(new TabuList(TABU_SIZE))
{}

DecisionPair * NeighborSelectingBestImprovementTabu::select(PSP *psp, Neighborhood * V)
{
    current_config = psp->GetCurrentSolution()->GetConfiguration();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->GetConfiguration();
    int best_found_cost = current_cost;

    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        //sol = new Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost && !tabu_list->isTabu(config))
        {
            best_found_cost   = c;
            best_found_config = config;
        }
    }
    tabu_list->push(best_found_config);
    rPair->update(current_config, best_found_config);
    //DecisionPair * p = new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
    return rPair;
}
