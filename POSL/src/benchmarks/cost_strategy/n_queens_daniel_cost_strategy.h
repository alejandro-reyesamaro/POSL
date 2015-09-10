#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

class NQueensDanielCostStrategy : public SolutionCostStrategy
{
    public:
        NQueensDanielCostStrategy(int n);
        int solutionCost(std::vector<int> configuration);

    private:
        int N;
        std::vector<int> err_d1;
        std::vector<int> err_d2;
        std::vector<unsigned int> flags;
};
