#pragma once

/**
 * POSL
 *
 * \file subsum_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Subsum Sequence Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "subsum_cost_structure.h"

#include <memory>

/*!
 * \class SubsumCostStrategy subsum_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Subsum Sequence Problem
 */
class SubsumCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param values The array with the values.
            \param subsum Subsum to find.
            \param n The number of values adding up to <b>subsum</b>.
         */
        SubsumCostStrategy(std::vector<int> values, int subsum, int n);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! Subsum Sequence cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<SubsumCostStructure> cost_structure;
};
