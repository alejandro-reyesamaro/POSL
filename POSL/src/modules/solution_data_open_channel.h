#pragma once

#include "data_open_channel.h"

class SolutionDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionDataOpenChannel(std::shared_ptr<Benchmark> _bench);
        int dataTag();
        std::shared_ptr<ComputationData> unpackMessage(int * buffer, std::shared_ptr<PSP> psp);

    private:
        std::shared_ptr<Solution> solution_data;
};
