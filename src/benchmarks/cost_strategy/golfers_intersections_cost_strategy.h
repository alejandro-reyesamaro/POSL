#pragma once

/**
 * POSL
 *
 * \file golfers_intersections_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"

/*!
 * \class GolfersIntersectionsCostStrategy golfers_intersections_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 */
class GolfersIntersectionsCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _groups Number of groups.
            \param _players Number of players per gruop (total of players = _groups * _players).
            \param _weeks Number of weeks.
         */
        GolfersIntersectionsCostStrategy(int _groups, int _players, int _weeks);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Variable to store a permutation
        std::vector<int> perm;
};

