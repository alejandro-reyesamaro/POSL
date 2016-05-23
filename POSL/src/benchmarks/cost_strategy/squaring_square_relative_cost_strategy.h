#pragma once

#include "relative_cost_strategy.h"
#include "squaring_square_cost_structure.h"
#include "sickest_variable_strategy.h"

class SquaringSquareRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        SquaringSquareRelativeCostStrategy(int _size, std::vector<int> _squares);

        void initializeCostData(std::vector<int> & _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> & _configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes change);
        void updateConfiguration(std::vector<int> & new_config);
        int currentCost() { return cost_str->CurrentCost; }
        int costOnVariable(int index);
        int sickestVariable();

    private:
        std::shared_ptr<SquaringSquareCostStructure> cost_str;
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
