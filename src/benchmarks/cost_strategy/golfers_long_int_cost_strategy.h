#pragma once

/**
 * POSL
 *
 * \file golfers_long_int_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"

/*!
 * \class GolfersLongIntCostStrategy golfers_long_int_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Social Golgers Problem
 */
class GolfersLongIntCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _groups Number of groups.
            \param _players Number of players per gruop (total of players = _groups * _players).
            \param _weeks Number of weeks.
         */
        GolfersLongIntCostStrategy(int _groups, int _players, int _weeks);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Variable to store whether a player is playing more than once ina week
        LongInt alldiff;
        //! Auxiliar variable to store a new partner
        LongInt new_partner;
        //! Auxiliar variable to store a global partnership of a player
        LongInt global_partnership;
        //! Variable to store the partners of each player (globally)
        std::vector<LongInt> global_partners;
        //! Variable to store the partners of each player (in a group)
        std::vector<LongInt> group_partners;
};
