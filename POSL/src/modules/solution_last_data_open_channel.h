#pragma once

#include "data_open_channel.h"

class SolutionLastDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionLastDataOpenChannel(std::string name, std::shared_ptr<Benchmark>_bench);
        int dataID();
        std::string codeToSend();

        std::shared_ptr<ComputationData> storeMessage(int * buffer, std::shared_ptr<PSP>);

    private:
        std::shared_ptr<Solution> solution_data;
};
