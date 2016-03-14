#pragma once

#include "relative_cost_strategy.h"
#include "costas_array_cost_structure.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/randomizer.h"

#include <memory>

class CostasArrayRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        CostasArrayRelativeCostStrategy(int n);

        void initializeCostData(vector<int> &_configuration, int initial_cost);
        int relativeSolutionCost(vector<int> &_configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes);
        void updateConfiguration(vector<int> & new_config);
        int currentCost() { return ca_str->CurrentCost; }
        int costOnVariable(int i);
        int sickestVariable();

        std::vector<int> Reset();//vector<int> &current_configuration);

    private:

        int N;
        std::shared_ptr<CostasArrayCostStructure> ca_str;
        FixedSizeVector<int> bad_variables;
};
