#include "neighbor_selecting_best_improvement_tabu.h"

#define TABU_SIZE 10

NeighborSelectingBestImprovementTabu::NeighborSelectingBestImprovementTabu()
    : tabu_list(new TabuList(TABU_SIZE))
{}

DecisionPair * NeighborSelectingBestImprovementTabu::select(PSP *psp, Neighborhood * V)
{
    current_solution = psp->GetCurrentSolution();
    int current_cost = psp->CurrentCost();

    it = V->getIterator();

    best_found = current_solution->GetConfiguration();
    int best_found_cost = current_cost;

    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        //sol = new Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost && !tabu_list->isTabu(config))
        {
            best_found_cost = c;
            best_found      = config;
        }
    }
    tabu_list->push(best_found);
    DecisionPair * p = new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
    return p;
}
