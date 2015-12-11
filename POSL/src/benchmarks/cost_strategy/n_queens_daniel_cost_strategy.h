#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "n_queens_cost_structure.h"

#include <memory>

class NQueensDanielCostStrategy : public SolutionCostStrategy
{
    public:
        NQueensDanielCostStrategy(int n);
        int solutionCost(std::vector<int> configuration);

    private:
        int N;
        std::shared_ptr<NQueensCostStructure> nq_str;
};
