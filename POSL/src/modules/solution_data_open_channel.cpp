#include "solution_data_open_channel.h"
#include "../packing/packers/solution_packer.h"

SolutionDataOpenChannel::SolutionDataOpenChannel(shared_ptr<Benchmark> _bench)
    : DataOpenChannel(_bench),
      solution_data(make_shared<Solution>(_bench->Domains()))
{}

int SolutionDataOpenChannel::dataTag()
{
    return SOLUTION_PACKING_ID;
}

shared_ptr<ComputationData> SolutionDataOpenChannel::unpackMessage(int * buffer, shared_ptr<PSP> psp)
{
    solution_data->UpdateConfigurationFromPack(buffer);
    return solution_data;
}
