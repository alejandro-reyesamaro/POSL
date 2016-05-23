#pragma once

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "squaring_square_cost_structure.h"

class SquaringSquareSuperpositionCostStrategy : public SolutionCostStrategy
{
    public:
        SquaringSquareSuperpositionCostStrategy(int _size, std::vector<int> _squares);
        int solutionCost(std::vector<int> &configuration);

    private:
        //! [Size of the big square]
        int size;
        //! [Sizes of the squares to put into the big one]
        std::vector<int> squares;        
        std::shared_ptr<SquaringSquareCostStructure> cost_struct;
};
