#pragma once

#include "data_open_channel.h"

class SolutionDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionDataOpenChannel(shared_ptr<Benchmark> _bench);
        int dataTag();
        shared_ptr<ComputationData> unpackMessage(int * buffer, shared_ptr<PSP> psp);

    private:
        shared_ptr<Solution> solution_data;
};
