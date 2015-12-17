#include "psp.h"

#include <algorithm>
#include <iostream>

using namespace std;

PSP::PSP(std::shared_ptr<Benchmark> _bench, int _pID)
    : bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_configuration(_bench->Domains().size(),1),
      best_found_cost(1000),
      pID(_pID),
      outer_information(false)
{}

PSP::PSP(std::shared_ptr<Benchmark> _bench)
    : PSP (_bench, -1)
{}


void PSP::UpdateSolution(vector<int> config)
{
    bench->UpdateSolution(config);
    int cost = bench->currentCost();
    int best_cost = BestCostSoFar();
    if(cost < best_cost)
    {
        copy(config.begin(), config.end(), best_found_configuration.begin());
        best_found_cost = cost;
    }    
}

void PSP::Start(vector<int> config)
{
    bench->InitializeCostData(config);    
    //bench->UpdateSolution(config);
    if(iterations == 0)
    {
        copy(config.begin(), config.end(), best_found_configuration.begin());
        best_found_cost = bench->currentCost();
    }
}

void PSP::UpdateTime(int _milisecs){ milisecs = _milisecs; }

void PSP::CountIteration(){ iterations ++; }
