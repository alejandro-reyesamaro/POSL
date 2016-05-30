#pragma once

/**
 * POSL
 *
 * \file squaring_square_superposition_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Squaring the Square Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "squaring_square_cost_structure.h"

/*!
 * \class SquaringSquareSuperpositionCostStrategy squaring_square_superposition_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Squaring the Square Problem
 */
class SquaringSquareSuperpositionCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _size Size of the big square.
            \param _squares Sizes of the squares.
         */
        SquaringSquareSuperpositionCostStrategy(int _size, std::vector<int> _squares);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> &configuration);

    private:
        //! [Size of the big square]
        int size;
        //! [Sizes of the squares to put into the big one]
        std::vector<int> squares;
        //! Squaring the Square cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<SquaringSquareCostStructure> cost_struct;
};
