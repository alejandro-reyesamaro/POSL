#pragma once

#include "../../tools/t_changes.h"
#include "../../data/seed.h"

#include <vector>

class RelativeCostStrategy
{
    public:
        virtual int relativeSolutionCost(std::vector<int> & _configuration) = 0;
        virtual void initializeCostData(std::vector<int> & _configuration, int initial_cost) = 0;
        virtual int relativeSolutionCost(std::vector<int> & new_config, T_Changes change) = 0;
        virtual void updateConfiguration(std::vector<int> & new_config) = 0;
        virtual int currentCost() = 0;

        virtual int costOnVariable(int i) = 0;
        virtual int sickestVariable() = 0;
};
