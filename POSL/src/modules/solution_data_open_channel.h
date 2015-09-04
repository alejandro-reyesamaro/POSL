#pragma once

#include "data_open_channel.h"

class SolutionDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionDataOpenChannel(Benchmark * _bench);
        int dataTag();
        ComputationData * unpackMessage(int * buffer, PSP * psp);

    private:
        Solution * solution_data;
};
