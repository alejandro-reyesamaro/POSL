#include "decision_pair_data_open_channel.h"
#include "../data/dStrategy/decision_pair_packing_strategy.h"

#include "mpi.h"

DecisionPairDataOpenChannel::DecisionPairDataOpenChannel()
{
}

int DecisionPairDataOpenChannel::dataTag()
{
    return DECISIONPAIR_PACKING_ID;
}

ComputationData * DecisionPairDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    DecisionPair * rPair = DecisionPairPackingStrategy::unpack(buffer, psp->GetBenchmark()->Domains());
    return rPair;
}
