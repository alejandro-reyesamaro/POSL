#include "solution_data_open_channel.h"
#include "../packing/packers/solution_packer.h"

using namespace std;

SolutionDataOpenChannel::SolutionDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Domains()))
{}

int SolutionDataOpenChannel::dataTag()
{
    return SOLUTION_PACKING_ID;
}

std::shared_ptr<ComputationData> SolutionDataOpenChannel::unpackMessage(int * buffer, std::shared_ptr<PSP>)
{
    solution_data->UpdateConfigurationFromPack(buffer);
    return solution_data;
}
