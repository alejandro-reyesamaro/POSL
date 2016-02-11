#pragma once

#include "data_open_channel.h"

class SolutionBestDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionBestDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();

        std::shared_ptr<ComputationData> storeMessage(int * buffer, std::shared_ptr<PSP> psp);

    private:
        std::shared_ptr<Solution> solution_data;
        std::shared_ptr<Solution> best_solution_data;
        int best_cost;
};
