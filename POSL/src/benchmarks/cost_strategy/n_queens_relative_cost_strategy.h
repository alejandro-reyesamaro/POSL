#pragma once

#include "relative_cost_strategy.h"
#include "n_queens_cost_structure.h"

#include <memory>

class NQueensRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        NQueensRelativeCostStrategy(int n);

        void initializeCostData(std::vector<int> _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> _configuration);
        int relativeSolutionCost(std::vector<int> new_config, T_Changes change);
        void updateConfiguration(std::vector<int> new_config);
        int currentCost() { return nq_str->CurrentCost; } //{ return current_cost; }

    private:
        int relative_cost(std::vector<int> new_config, T_Changes change, bool updating);

        int N;
        std::shared_ptr<NQueensCostStructure> nq_str;
        //std::vector<int> err_d1;
        //std::vector<int> err_d2;
        //std::vector<unsigned int> flags;
        //std::vector<int> configuration;
        //int current_cost;
};

