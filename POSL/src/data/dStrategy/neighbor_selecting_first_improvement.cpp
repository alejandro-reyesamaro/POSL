#include "neighbor_selecting_first_improvement.h"

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement(vector<Domain> domains)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domains), make_shared<Solution>(domains)))
{}

shared_ptr<DecisionPair> NeighborSelectingFirstImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
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
        //sol = make_shared<Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = config;
            break;
        }
    }
    //DecisionPair * p = make_shared<DecisionPair(current_solution, make_shared<Solution(psp->GetBenchmark()->Domains(), best_found));
    rPair->update(current_config, best_found_config);
    return rPair;
}
