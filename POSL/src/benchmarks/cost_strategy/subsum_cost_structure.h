#pragma once

#include <vector>
#include <list>
#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"

class SubsumCostStructure : public ProjectableCost
{
    public:
        SubsumCostStructure(std::vector<int> values, int subsum, unsigned int n);

        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void init(std::vector<int> config);
        int costOnVariable(int index);
        void reset();

        int Subsum;
        int N;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        int current_sum;
};
