#pragma once

#include "data_open_channel.h"

class NeighborhoodDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodDataOpenChannel(Benchmark * _bench);
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);
};
