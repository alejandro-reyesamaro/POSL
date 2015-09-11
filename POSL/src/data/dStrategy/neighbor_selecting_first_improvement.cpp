#include "neighbor_selecting_first_improvement.h"
#include "../../tools/tools.h"

#include <iostream>

using namespace std;

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement(vector<Domain> domains)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domains), make_shared<Solution>(domains)))
{}

shared_ptr<DecisionPair> NeighborSelectingFirstImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    //vector<int> cfg = V->CurrentConfiguration();
    //cout << "Neighborhood of:    " << Tools::configurationToString(cfg) << endl;
    //cout << " with cost :" << psp->GetBenchmark()->solutionCost(cfg) << "-- : " << endl;


    current_config = psp->GetCurrentSolution()->GetConfiguration();
    //cout << "()" << Tools::configurationToString(current_config) << endl;
    //cout << endl;

    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->GetConfiguration();
    int best_found_cost = current_cost;

    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        //cout << "(" << psp->GetBenchmark()->solutionCost(cfg) << ")- " << Tools::configurationToString(config) << endl;
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
