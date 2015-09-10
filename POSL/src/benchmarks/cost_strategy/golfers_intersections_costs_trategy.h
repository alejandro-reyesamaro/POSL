#pragma once

#include "solution_cost_strategy.h"

class GolfersIntersectionsCostStrategy : public SolutionCostStrategy
{
    public:
        GolfersIntersectionsCostStrategy(int _groups, int _players, int _weeks);
        int solutionCost(std::vector<int> configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        std::vector<int> perm;
};

