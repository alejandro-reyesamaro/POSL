#include "psp.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define EXIT_TIME 300000

PSP::PSP(shared_ptr<Benchmark> _bench, int _pID, string _logs_path)
    : bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_configuration(_bench->Domains().size(),1),
      best_found_cost(100000),
      pID(_pID),
      outer_information(false),
      found_thanks_outer_information(false),
      time_out(EXIT_TIME),
      plog(max(0, _pID), _logs_path),
      logs_path(_logs_path)
{}

PSP::PSP(shared_ptr<Benchmark> _bench, int _pID)
    : PSP (_bench, _pID, "./logs")
{}

PSP::PSP(shared_ptr<Benchmark> _bench)
    : PSP (_bench, -1, "./logs")
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
        found_thanks_outer_information = outer_information;
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

void PSP::log(std::string text){ plog.log(text); }
