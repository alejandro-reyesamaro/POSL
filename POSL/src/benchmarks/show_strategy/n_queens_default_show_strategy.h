#pragma once

#include "show_strategy.h"

class NQueensDefaultShowStrategy : public ShowStrategy
{
    public:
        NQueensDefaultShowStrategy(int n);
        std::string showSolution(std::shared_ptr<Solution> & solution);

    private:
        int N;
};
