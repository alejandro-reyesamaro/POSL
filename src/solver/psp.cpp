#include "psp.h"

#include <algorithm>
#include <iostream>
#include <climits>
#include <ctime>

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
      //plog(max(0, _params->pID), _params->logs_path),
      //logs_path(params->logs_path),
      restarts(-1),
      rand(make_shared<Randomizer>(_bench->Dimension(), max(0, _params->pID))),
      tabu_object(make_shared<TabuObject>(_bench->Dimension(),
                                          _params->GetTabuListSize(),
                                          _params->GetTabuEps(),
                                          _params->GetTabuNormType())),      
      params(_params),
      data_counters(4,0),
      data_times_averages(4,0),
      sum(0.0)
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


void PSP::report_sent_package(int tics)
{
    store_information_exchange_statistic(tics, data_counters[0], data_times_averages[0]);
}

int PSP::get_average_time_of_sent_packages()
{
    return (data_counters[0] == 0)
            ? 0
            : (int((double(data_times_averages[0]) / CLOCKS_PER_SEC)*1000))/data_counters[0];
}

void PSP::report_received_package(int tics)
{
    store_information_exchange_statistic(tics, data_counters[1], data_times_averages[1]);
}

int PSP::get_average_time_of_received_packages()
{
    return int((double(data_times_averages[1]) / CLOCKS_PER_SEC)*1000);
    //return data_times_averages[1];
}

void PSP::report_accepted_package(){ data_counters[2] ++; }

void PSP::report_traveling_package(int tics)
{
    store_information_exchange_statistic(tics, data_counters[3], data_times_averages[3]);
}

int PSP::get_average_time_of_traveling_packages()
{
    return int((double(data_times_averages[3]) / CLOCKS_PER_SEC)*1000);
}

void PSP::store_information_exchange_statistic(int tics, int & packages_count, int & time)
{
    sum = (double)(packages_count * time);
    sum += (double)tics;
    packages_count ++;
    time = int(sum / packages_count);
}
