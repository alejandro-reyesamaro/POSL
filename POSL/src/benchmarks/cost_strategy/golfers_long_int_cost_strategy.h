#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

class GolfersLongIntCostStrategy : public SolutionCostStrategy
{
    public:
        GolfersLongIntCostStrategy(int _groups, int _players, int _weeks);
        int solutionCost(std::vector<int> configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //std::vector<int> perm;
        LongInt alldiff;
        LongInt new_partner;
        LongInt global_partnership;
        std::vector<LongInt> global_partners;
        std::vector<LongInt> group_partners;
};
