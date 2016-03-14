#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

class Golfers3PNCostStrategy : public SolutionCostStrategy
{
    public:
        Golfers3PNCostStrategy(int _groups, int _players, int _weeks);
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        LongInt alls;
        //LongInt new_partner;
        //LongInt global_partnership;
        std::vector<LongInt> group_partners;
        std::vector<LongInt> global_partners;
        std::vector<LongInt> repetitions;
        std::vector<int> perm;
};
