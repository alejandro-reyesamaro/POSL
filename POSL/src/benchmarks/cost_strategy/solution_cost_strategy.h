#pragma once

/**
 * POSL
 *
 * \file solution_cost_strategy.h
 * \brief Interface to represent an absolute solution cost strategy
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include <vector>

/*!
 * \class SolutionCostStrategy solution_cost_strategy.h
 * \brief Interface to represent an absolute solution cost strategy
 */
class SolutionCostStrategy
{
    public:
        //! Computes the cost of a configuration.
        /*!
            \param _configuration A configuration (solution).
            \return Cost of the given configuration.
         */
        virtual int solutionCost(std::vector<int> & configuration) = 0;
};
