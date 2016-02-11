#pragma once

#include "data_open_channel.h"
#include "../data/decision_pair.h"

class DecisionPairLastDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairLastDataOpenChannel(std::string name, std::shared_ptr<Benchmark>_bench);
        int dataID();
        std::string codeToSend();

        std::shared_ptr<ComputationData> storeMessage(int * buffer, std::shared_ptr<PSP>);

    private:
        std::shared_ptr<DecisionPair> pair_data;
};
