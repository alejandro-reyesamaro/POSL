#pragma once

#include "data_open_channel.h"

class DecisionPairDataOpenChannel : public DataOpenChannel
{
    public:
        DecisionPairDataOpenChannel();
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);
};
