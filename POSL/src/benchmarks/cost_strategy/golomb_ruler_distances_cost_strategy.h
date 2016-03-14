#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

class GolombRulerDistancesCostStrategy : public SolutionCostStrategy
{
    public:
        GolombRulerDistancesCostStrategy(int _order, int _length);
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [Number of marcs], [Maximum distance]
        int order, length;

        LongInt measures;
};
