#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "all_intervals_cost_structure.h"

#include <memory>

class AllIntervalsDanielCostStrategy : public SolutionCostStrategy
{
    public:
        AllIntervalsDanielCostStrategy(int n);
        int solutionCost(std::vector<int> & configuration);

    private:
        std::shared_ptr<AllIntervalsCostStructure> cost_str;
};
