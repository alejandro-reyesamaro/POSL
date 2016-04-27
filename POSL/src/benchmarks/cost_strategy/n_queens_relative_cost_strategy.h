#pragma once

#include "relative_cost_strategy.h"
#include "n_queens_cost_structure.h"
#include "sickest_variable_strategy.h"

#include <memory>

class NQueensRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        NQueensRelativeCostStrategy(int n);

        void initializeCostData(std::vector<int> & _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> & _configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes change);
        void updateConfiguration(std::vector<int> & new_config);
        int currentCost() { return nq_str->CurrentCost; }

        int costOnVariable(int i);
        int sickestVariable();

    private:
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);

        std::shared_ptr<NQueensCostStructure> nq_str;
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};

