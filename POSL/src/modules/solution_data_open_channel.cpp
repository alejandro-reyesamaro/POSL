#include "solution_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

SolutionDataOpenChannel::SolutionDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Domains()))
{}

int SolutionDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_TOK) + "(" + name + ")";
}

std::shared_ptr<ComputationData> SolutionDataOpenChannel::unpackMessage(int * buffer, std::shared_ptr<PSP>)
{
    solution_data->UpdateConfigurationFromPack(buffer);
    return solution_data;
}
