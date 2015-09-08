#pragma once

#include "data_open_channel.h"

class NeighborhoodDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodDataOpenChannel(shared_ptr<Benchmark> _bench);
        int dataTag();
        shared_ptr<ComputationData> unpackMessage(int * buffer, shared_ptr<PSP> psp);
};
