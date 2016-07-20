#pragma once

/**
 * POSL
 *
 * \file golomb_ruler_distances_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

/*!
 * \class GolombRulerDistancesCostStrategy golomb_ruler_distances_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Golomb Ruler Problem
 */
class GolombRulerDistancesCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _order Problem order: number of marks.
            \param _length Maximal measure (final mark).
         */
        GolombRulerDistancesCostStrategy(int _order, int _length);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [Number of marcs], [Maximum distance]
        int order, length;

        //! Measures already into the configuration
        LongInt measures;
};
