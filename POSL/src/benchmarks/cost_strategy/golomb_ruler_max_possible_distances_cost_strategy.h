#pragma once

#include "solution_cost_strategy.h"
#include "golomb_ruler_cost_structure.h"

#include <memory>

class GolombRulerMaxPossibleDistancesCostStrategy : public SolutionCostStrategy
{
    public: //! [Number of marcs], [Maximum distance]
        GolombRulerMaxPossibleDistancesCostStrategy(int _order, int _length);
        int solutionCost(std::vector<int> & configuration);

    private:
        std::shared_ptr<GolombRulerCostStructure> cost_structure;
};
