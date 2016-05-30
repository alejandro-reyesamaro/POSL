#pragma once

/**
 * POSL
 *
 * \file squaring_square_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Squaring the Square Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "squaring_square_cost_structure.h"
#include "sickest_variable_strategy.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/randomizer.h"

/*!
 * \class SquaringSquareRelativeCostStrategy squaring_square_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Squaring the Square Problem
 */
class SquaringSquareRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _size Size of the big square.
            \param _squares Sizes of the squares.
         */
        SquaringSquareRelativeCostStrategy(int _size, std::vector<int> _squares);

        //! From <RelativeCostStrategy>
        void initializeCostData(std::vector<int> & _configuration, int _initial_cost);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration, T_Changes _change);

        //! From <RelativeCostStrategy>
        void updateConfiguration(std::vector<int> & new_config);

        //! From <RelativeCostStrategy>
        int costOnVariable(int index);

        //! From <RelativeCostStrategy>
        int sickestVariable();

        //! (Property) From <RelativeCostStrategy>
        int currentCost() { return cost_str->CurrentCost; }

    private:
        //! Squaring the Square cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<SquaringSquareCostStructure> cost_str;

        //! Strategy to compute the most troubled variable.
        /*!
            In this problem, the strategy is by default: select the index of a variable
            with the highest projected cost, using the function <b>sickestVariable()</b>
        */
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;

        //! A temporal vector to store the dab variables (same projected cost)
        FixedSizeVector<int> bad_variables;
        //! Random generator to choose the <i>bad variable</i>
        RandomGenerator r_gen;
};
