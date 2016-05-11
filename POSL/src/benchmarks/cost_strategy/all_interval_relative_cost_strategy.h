#pragma once

#include "relative_cost_strategy.h"
#include "all_intervals_cost_structure.h"
#include "sickest_variable_strategy.h"

#include <memory>

class AllIntervalRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        AllIntervalRelativeCostStrategy(int n);

        void initializeCostData(vector<int> &_configuration, int initial_cost);
        int relativeSolutionCost(vector<int> &_configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes);
        void updateConfiguration(vector<int> & new_config);
        int currentCost() { return cost_str->CurrentCost; }
        int costOnVariable(int i);
        int sickestVariable();

        std::vector<int> Reset();

    private:

        std::shared_ptr<AllIntervalsCostStructure> cost_str;
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
