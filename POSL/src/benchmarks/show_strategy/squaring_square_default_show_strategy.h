#pragma once

#include "show_strategy.h"

class SquaringSquareDefaultShowStrategy : public ShowStrategy
{
    public:
        SquaringSquareDefaultShowStrategy(int _n_squares);
        std::string showSolution(std::shared_ptr<Solution> & solution);

    private:
        //! [number of square]
        int n_squares;
};
