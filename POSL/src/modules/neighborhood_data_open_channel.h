#pragma once

#include "data_open_channel.h"

class NeighborhoodDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodDataOpenChannel(std::shared_ptr<Benchmark> _bench);
        int dataTag();
        std::shared_ptr<ComputationData> unpackMessage(int * buffer, std::shared_ptr<PSP> psp);
};
