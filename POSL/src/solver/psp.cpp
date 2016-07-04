#include "psp.h"

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define EXIT_TIME 300000

PSP::PSP(shared_ptr<Benchmark> _bench, int _pID)
    : PSP (_bench, make_shared<SearchProcessParamsStruct>())//PSP (_bench, _pID, "./logs")
{
    params->SetID(_pID);
}

PSP::PSP(shared_ptr<Benchmark> _bench)
    : PSP (_bench, make_shared<SearchProcessParamsStruct>())//-1, "./logs")
{}

PSP::PSP(std::shared_ptr<Benchmark> _bench, std::shared_ptr<SearchProcessParamsStruct> _params)
    : bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_configuration(_bench->Dimension(),1),
      best_found_cost(INT_MAX),
      //pID(params->pID),
      outer_information(false),
      found_thanks_outer_information(false),
      //time_out(params->max_time_miliseconds),
      plog(max(0, _params->pID), _params->logs_path),
      //logs_path(params->logs_path),
      restarts(-1),
      rand(make_shared<Randomizer>(_bench->Dimension(), max(0, _params->pID))),
      tabu_object(make_shared<TabuObject>(_bench->Dimension(),
                                          _params->GetpTabuListSize(),
                                          _params->GetTabuEps(),
                                          _params->GetpTabuNormType())),
      params(_params)
{}

void PSP::clear_information()
{
    iterations = 0;
    milisecs = 0;
    fill(best_found_configuration.begin(), best_found_configuration.end(),1);
    best_found_cost = INT_MAX;
    outer_information = false;
    found_thanks_outer_information = false;
    restarts = -1;
}

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
    if(iterations <= 0)
    {
        copy(config.begin(), config.end(), best_found_configuration.begin());
        best_found_cost = bench->currentCost();
    }
}

void PSP::UpdateTime(int _milisecs){ milisecs = _milisecs; }

void PSP::CountIteration(){ iterations ++; }

void PSP::StartSearch(){ restarts ++ ;}

//void PSP::log(std::string text){ plog.log(text); }
