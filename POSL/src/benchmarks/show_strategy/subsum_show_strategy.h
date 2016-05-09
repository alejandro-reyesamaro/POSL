#pragma once

#include "show_strategy.h"

class SubsumShowStrategy : public ShowStrategy
{
    public:
        SubsumShowStrategy(std::vector<int> _values, int _n);
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        std::vector<int> values;
        int n;
};
