#pragma once

#include "data_open_channel.h"

class NeighborhoodDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();
        std::shared_ptr<ComputationData> unpackMessage(int * buffer, std::shared_ptr<PSP>);
};
