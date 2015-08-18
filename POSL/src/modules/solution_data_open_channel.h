#pragma once

#include "data_open_channel.h"

class SolutionDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionDataOpenChannel();
        ComputationData * execute(PSP * psp, ComputationData * input);
};
