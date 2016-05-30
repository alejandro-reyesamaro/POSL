#include "neighbor_selecting_first_improvement_global_tabu.h"

using namespace std;

NeighborSelectingFirstImprovementGlobalTabu::NeighborSelectingFirstImprovementGlobalTabu(shared_ptr<Domain> domain, int dimension)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domain, dimension), make_shared<Solution>(domain, dimension)))
{}

shared_ptr<DecisionPair> NeighborSelectingFirstImprovementGlobalTabu::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V, float eps)
{
    current_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int best_found_cost = current_cost;
    int c;
    it = V->getIterator();
    it->Reset();
    bool is_global_tabu = false;

    while(it->SomeNext())
    {
        neighbor = it->GetNext();
        c = psp->GetBenchmark()->relativeSolutionCost(neighbor);
        is_global_tabu = (eps == 0) ? psp->GetTabuObject()->isGlobalTabu(neighbor)
                                    : psp->GetTabuObject()->isGlobalTabu(neighbor,eps);
        if (!is_global_tabu)
            if(c < best_found_cost)
            {
                best_found_cost   = c;
                best_found_config = neighbor;
                break;
            }
            //else if(c = best_found_cost && psp->GetRandomizer()->bernoulli(0.5))
            //    best_found_config = neighbor;

    }
    rPair->update(current_config, best_found_config);
    return rPair;
}
