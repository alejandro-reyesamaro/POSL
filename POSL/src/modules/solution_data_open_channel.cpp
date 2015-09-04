#include "solution_data_open_channel.h"
#include "../packing/packers/solution_packer.h"

SolutionDataOpenChannel::SolutionDataOpenChannel(Benchmark * _bench)
    : DataOpenChannel(_bench),
      solution_data(new Solution(_bench->Domains()))
{}

int SolutionDataOpenChannel::dataTag()
{
    return SOLUTION_PACKING_ID;
}

ComputationData * SolutionDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    solution_data->UpdateConfigurationFromPack(buffer);
    return solution_data;
}
