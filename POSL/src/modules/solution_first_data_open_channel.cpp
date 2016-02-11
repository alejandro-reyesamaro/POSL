#include "solution_first_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

SolutionFirstDataOpenChannel::SolutionFirstDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Domains()))
{}

int SolutionFirstDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionFirstDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_FIRST_TOK) + "(" + name + ")";
}

shared_ptr<ComputationData> SolutionFirstDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    if(!ContainsInformation())
    {
        solution_data->UpdateConfigurationFromPack(buffer);
        return solution_data;
    }
}
