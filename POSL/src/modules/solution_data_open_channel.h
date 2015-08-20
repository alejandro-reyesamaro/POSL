#pragma once

#include "data_open_channel.h"

class SolutionDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionDataOpenChannel();
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);
};
