#pragma once

#include "data_open_channel.h"

class SolutionFirstDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionFirstDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();

        void storeMessage(int * buffer, std::shared_ptr<PSP>);
        shared_ptr<ComputationData> selectMessage();

    private:
        std::shared_ptr<Solution> received_data;
};