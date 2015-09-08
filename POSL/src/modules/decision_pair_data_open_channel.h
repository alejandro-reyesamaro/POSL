#pragma once

#include "data_open_channel.h"
#include "../data/decision_pair.h"

class DecisionPairDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairDataOpenChannel(shared_ptr<Benchmark>_bench);
        int dataTag();
        shared_ptr<ComputationData> unpackMessage(int * buffer, shared_ptr<PSP> psp);

    private:
        shared_ptr<DecisionPair> pair_data;
};
