#pragma once

/**
 * POSL
 *
 * \file golfers_3pn_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

/*!
 * \class Golfers3PNCostStrategy golfers_3pn_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 */
class Golfers3PNCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _groups Number of groups.
            \param _players Number of players per gruop (total of players = _groups * _players).
            \param _weeks Number of weeks.
         */
        Golfers3PNCostStrategy(int _groups, int _players, int _weeks);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Auxiliar variable with all bits activated
        LongInt alls;
        //! Variable to store the partners of each player (in a group)
        std::vector<LongInt> group_partners;
        //! Variable to store the partners of each player (globally)
        std::vector<LongInt> global_partners;
        //! Variable to store whether a player is playing more than once ina week
        std::vector<LongInt> repetitions;
        //! Variable to store a permutation
        std::vector<int> perm;
};
