#include "neighbor_selecting_first_improvement.h"
#include "../../tools/tools.h"

#include <iostream>

using namespace std;

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement(shared_ptr<Domain> domain, int dimension)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domain, dimension), make_shared<Solution>(domain, dimension)))
{}

shared_ptr<DecisionPair> NeighborSelectingFirstImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    //cout << "first... " << endl;
    current_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int best_found_cost = current_cost;
    int c;

    //cout << "first (it)... " << endl;
    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        neighbor = it->GetNext();
        //cout << Tools::configurationToString(config) << endl;
        c = psp->GetBenchmark()->relativeSolutionCost(neighbor);
        //cout << c << endl;
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = neighbor;
            //cout << "better has been found : " << c << endl;
            break;
        }
    }
    rPair->update(current_config, best_found_config);
    //cout << "... first" << endl;
    return rPair;
}
