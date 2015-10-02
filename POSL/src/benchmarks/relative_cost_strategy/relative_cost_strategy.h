#pragma once

#include "../../tools/t_changes.h"

#include <vector>

class RelativeCostStrategy
{
    public:
        virtual int relativeSolutionCost(std::vector<int> _configuration) = 0;
        virtual void initializeCostData(std::vector<int> _configuration, int initial_cost) = 0;
        virtual int relativeSolutionCost(std::vector<int> new_config, T_Changes change) = 0;
        virtual void updateConfiguration(T_Changes change) = 0;
};
