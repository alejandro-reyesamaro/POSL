#include "neighbor_selecting_first_improvement.h"

#include <iostream>

using namespace std;

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement(vector<Domain> domains)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domains), make_shared<Solution>(domains)))
{}

shared_ptr<DecisionPair> NeighborSelectingFirstImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    current_config = psp->GetCurrentSolution()->GetConfiguration();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->GetConfiguration();
    int best_found_cost = current_cost;
    int c;

    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        c = psp->GetBenchmark()->relativeSolutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = config;
            cout << "better has been found : " << c << endl;
            break;
        }
    }
    rPair->update(current_config, best_found_config);
    return rPair;
}
