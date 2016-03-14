#pragma once

#include "show_strategy.h"

class GolombRulerDefaultShowStrategy : public ShowStrategy
{
    public:
        GolombRulerDefaultShowStrategy(int _order, int _length);
        std::string showSolution(std::shared_ptr<Solution> & solution);

    private:
        //! [Number of marcs], [Maximum distance]
        int order, length;
};
