#pragma once

/**
 * POSL
 *
 * \file golfers_default_show_strategy.h
 * \brief Class to represent the way Social Golfers problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class GolfersDefaultShowStrategy golfers_default_show_strategy.h
 * \brief Class to represent the way Social Golfers problem shows its result (solution)
 */
class GolfersDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _groups Number of groups.
            \param _players Number of players per gruop (total of players = _groups * _players).
            \param _weeks Number of weeks.
         */
        GolfersDefaultShowStrategy(int _groups, int _players, int _weeks);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
};
