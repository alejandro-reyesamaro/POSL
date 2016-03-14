#pragma once

#include "show_strategy.h"

class GolfersDefaultShowStrategy : public ShowStrategy
{
    public:
        GolfersDefaultShowStrategy(int _groups, int _players, int _weeks);
        std::string showSolution(std::shared_ptr<Solution> & solution);

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
};
