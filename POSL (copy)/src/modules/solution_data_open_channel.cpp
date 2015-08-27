#include "solution_data_open_channel.h"
#include "../data/dStrategy/solution_packing_strategy.h"

#include "mpi.h"

SolutionDataOpenChannel::SolutionDataOpenChannel()
{
}

int SolutionDataOpenChannel::dataTag()
{
    return SOLUTION_PACKING_ID;
}

ComputationData * SolutionDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    Solution * rSol = SolutionPackingStrategy::unpack(buffer, psp->GetBenchmark()->Domains());
    return rSol;
}


