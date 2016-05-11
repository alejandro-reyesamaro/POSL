#pragma once

#include "relative_cost_strategy.h"
#include "golomb_ruler_cost_structure.h"
#include "golomb_ruler_relative_cost_structure.h"
#include "sickest_variable_strategy.h"

class GolombRulerRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        GolombRulerRelativeCostStrategy(int _order, int _length);

        void initializeCostData(std::vector<int> & _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> & _configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes change);
        void updateConfiguration(std::vector<int> & new_config);
        int currentCost();
        int costOnVariable(int index);
        int sickestVariable();

    private:
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);

        //std::shared_ptr<GolombRulerRelativeCostStructure> cost_structure;
        std::shared_ptr<GolombRulerCostStructure> cost_structure;
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
