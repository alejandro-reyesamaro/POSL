#pragma once

#include "data_open_channel.h"
#include "../data/decision_pair.h"

class DecisionPairDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairDataOpenChannel(Benchmark *_bench);
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);

    private:
        DecisionPair * pair_data;
};
