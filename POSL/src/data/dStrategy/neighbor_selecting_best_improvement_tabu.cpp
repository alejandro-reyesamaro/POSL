#include "neighbor_selecting_best_improvement_tabu.h"

#define TABU_SIZE 10

using namespace std;

NeighborSelectingBestImprovementTabu::NeighborSelectingBestImprovementTabu(shared_ptr<Domain> domain, int dimension)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domain, dimension), make_shared<Solution>(domain, dimension))),
      tabu_list(make_shared<TabuList>(TABU_SIZE))
{}

shared_ptr<DecisionPair> NeighborSelectingBestImprovementTabu::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    current_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int best_found_cost = current_cost;
    int c;
    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        neighbor = it->GetNext();
        c = psp->GetBenchmark()->relativeSolutionCost(neighbor);

        if (!tabu_list->isTabu(neighbor))
            if(c < best_found_cost)
            {
                best_found_cost   = c;
                best_found_config = neighbor;
            }
            else if(c = best_found_cost && psp->GetRandomizer()->bernoulli(0.5))
                best_found_config = neighbor;

    }
    tabu_list->push(best_found_config);
    rPair->update(current_config, best_found_config);
    return rPair;
}
