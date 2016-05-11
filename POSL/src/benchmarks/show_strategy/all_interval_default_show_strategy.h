#pragma once

#include "show_strategy.h"

class AllIntervalDefaultShowStrategy : public ShowStrategy
{
    public:
        AllIntervalDefaultShowStrategy(int n);
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        int N;
};
