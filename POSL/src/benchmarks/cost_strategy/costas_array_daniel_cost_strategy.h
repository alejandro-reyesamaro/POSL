#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "costas_array_cost_structure.h"

#include <memory>

class CostasArrayDanielCostStrategy : public SolutionCostStrategy
{
    public:
        CostasArrayDanielCostStrategy(int n);
        int solutionCost(std::vector<int> configuration);

    private:
        int N;
        std::shared_ptr<CostasArrayCostStructure> ca_str;
};
