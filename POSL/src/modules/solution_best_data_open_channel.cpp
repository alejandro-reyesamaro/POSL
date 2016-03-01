#include "solution_best_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

SolutionBestDataOpenChannel::SolutionBestDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Domains())),
      best_solution_data(make_shared<Solution>(_bench->Domains()))
{}

int SolutionBestDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionBestDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_BEST_TOK) + "(" + name + ")";
}

shared_ptr<ComputationData> SolutionBestDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP> psp)
{
    if(ContainsInformation())
    {
        solution_data->UpdateConfigurationFromPack(buffer);
        int cost = psp->GetBenchmark()->solutionCost(best_solution_data);
        if(cost < best_cost)
        {
            best_solution_data = solution_data;
            best_cost = cost;
        }
    }
    else
    {
        best_solution_data->UpdateConfigurationFromPack(buffer);
        best_cost = psp->GetBenchmark()->solutionCost(best_solution_data);
    }
    return best_solution_data;
}