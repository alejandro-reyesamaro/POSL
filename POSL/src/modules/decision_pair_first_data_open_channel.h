#pragma once

#include "data_open_channel.h"
#include "../data/decision_pair.h"

class DecisionPairFirstDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairFirstDataOpenChannel(std::string name, std::shared_ptr<Benchmark>_bench);
        int dataID();
        std::string codeToSend();

        void storeMessage(int * buffer, std::shared_ptr<PSP>);
        shared_ptr<ComputationData> selectMessage();

    private:
        //std::shared_ptr<DecisionPair> cast_to_pair();
        std::shared_ptr<DecisionPair> received_data;
};
