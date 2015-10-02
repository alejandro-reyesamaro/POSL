#pragma once

#include "relative_cost_strategy.h"

class GolombRulerRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        GolombRulerRelativeCostStrategy();

        void initializeCostData(std::vector<int> _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> _configuration);
        int relativeSolutionCost(std::vector<int> new_config, T_Changes change);
        void updateConfiguration(T_Changes change);
};
