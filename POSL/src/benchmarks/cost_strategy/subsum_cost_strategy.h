#pragma once

#include "solution_cost_strategy.h"
#include "subsum_cost_structure.h"

#include <memory>

class SubsumCostStrategy : public SolutionCostStrategy
{
    public: //! [values], [Maximum distance]
        SubsumCostStrategy(std::vector<int> values, int subsum, int n);
        int solutionCost(std::vector<int> & configuration);

    private:
        std::shared_ptr<SubsumCostStructure> cost_structure;
};
