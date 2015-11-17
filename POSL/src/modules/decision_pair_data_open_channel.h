#pragma once

#include "data_open_channel.h"
#include "../data/decision_pair.h"

class DecisionPairDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairDataOpenChannel(std::string name, std::shared_ptr<Benchmark>_bench);
        int dataID();
        std::shared_ptr<ComputationData> unpackMessage(int * buffer, std::shared_ptr<PSP> psp);

    private:
        std::shared_ptr<DecisionPair> pair_data;
};
