#pragma once

#include "data_open_channel.h"

class SolutionBestDataOpenChannel : public DataOpenChannel
{
    public:
        SolutionBestDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();

        void storeMessage(int * buffer, std::shared_ptr<PSP> psp);

    private:
        std::shared_ptr<Solution> cast_to_solution();

        std::shared_ptr<Solution> solution_data;
        int best_cost;
        bool contains_information;
};
