#pragma once

#include "data_open_channel.h"

class NeighborhoodDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodDataOpenChannel();
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);
};
