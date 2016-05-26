#include "psp.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define EXIT_TIME 300000
#define TABU_SIZE 15

PSP::PSP(shared_ptr<Benchmark> _bench, int _pID, string _logs_path)
    : bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_configuration(_bench->Dimension(),1),
      best_found_cost(100000),
      pID(_pID),
      outer_information(false),
      found_thanks_outer_information(false),
      time_out(EXIT_TIME),
      plog(max(0, _pID), _logs_path),
      logs_path(_logs_path),      
      restarts(-1),
      rand(make_shared<Randomizer>(_bench->Dimension(), max(0, _pID))),
      tabu_list(make_shared<TabuList>(TABU_SIZE))
{}

PSP::PSP(shared_ptr<Benchmark> _bench, int _pID)
    : PSP (_bench, _pID, "./logs")
{}

PSP::PSP(shared_ptr<Benchmark> _bench)
    : PSP (_bench, -1, "./logs")
{}

void PSP::UpdateSolution(vector<int> & config)
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

void PSP::Start(vector<int> & config)
{
    bench->InitializeCostData(config);
    if(iterations == 0)
    {
        copy(config.begin(), config.end(), best_found_configuration.begin());
        best_found_cost = bench->currentCost();
    }
}

void PSP::UpdateTime(int _milisecs){ milisecs = _milisecs; }

void PSP::CountIteration(){ iterations ++; }

void PSP::StartSearch(){ restarts ++ ;}

//void PSP::log(std::string text){ plog.log(text); }

void PSP::addTabuSolution(vector<int> & configuration)
{
    tabu_list->push(configuration);
}

bool PSP::isGlobalTabu(vector<int> & configuration, float eps)
{
    return tabu_list->isTabuByNorm2(configuration, eps);
}

bool PSP::isGlobalTabu(vector<int> & configuration)
{
    return tabu_list->isTabu(configuration);
}
