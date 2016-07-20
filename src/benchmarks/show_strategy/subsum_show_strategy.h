#pragma once

/**
 * POSL
 *
 * \file subsum_show_strategy.h
 * \brief Class to represent the way Subsum Sequence problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class SubsumShowStrategy subsum_show_strategy.h
 * \brief Class to represent the way Subsum Sequence problem shows its result (solution)
 */
class SubsumShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _values The array with the values.
            \param n The number of values adding up to <b>subsum</b>.
         */
        SubsumShowStrategy(std::vector<int> _values, int _n);

        //! From <SolutionCostStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! The array with the values
        std::vector<int> values;
        //! The number of values adding up to the <i>subsum</i>
        int n;
};
