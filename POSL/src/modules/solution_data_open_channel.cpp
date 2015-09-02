#include "solution_data_open_channel.h"
#include "../packing/packers/solution_packer.h"

SolutionDataOpenChannel::SolutionDataOpenChannel()
{
}

int SolutionDataOpenChannel::dataTag()
{
    return SOLUTION_PACKING_ID;
}

ComputationData * SolutionDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    Solution * rSol = SolutionPacker::unpack(buffer, psp->GetBenchmark()->Domains());
    return rSol;
}
