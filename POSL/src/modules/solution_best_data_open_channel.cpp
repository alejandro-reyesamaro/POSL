#include "solution_best_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

SolutionBestDataOpenChannel::SolutionBestDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension()))
{
    received_data = make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension());
}

int SolutionBestDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionBestDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_BEST_TOK) + "(" + name + ")";
}

std::shared_ptr<Solution> SolutionBestDataOpenChannel::cast_to_solution()
{
    return static_pointer_cast<Solution>(received_data);
}

void SolutionBestDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP> psp)
{
    if(ContainsInformation())
    {
        solution_data->UpdateConfigurationFromPack(buffer);
        int cost = psp->GetBenchmark()->solutionCost(solution_data);
        if(cost < best_cost)
        {
            received_data = solution_data;
            best_cost = cost;
        }
    }
    else
    {
        cast_to_solution()->UpdateConfigurationFromPack(buffer);
        best_cost = psp->GetBenchmark()->solutionCost(cast_to_solution());
    }
}
