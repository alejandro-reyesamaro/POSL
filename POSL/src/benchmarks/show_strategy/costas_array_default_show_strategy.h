#pragma once

#include "show_strategy.h"

class CostasArrayDefaultShowStrategy : public ShowStrategy
{
    public:
        CostasArrayDefaultShowStrategy(int n);
        std::string showSolution(std::shared_ptr<Solution> & solution);

    private:
        int N;
};
