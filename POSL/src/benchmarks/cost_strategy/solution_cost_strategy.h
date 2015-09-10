#pragma once

#include <vector>

class SolutionCostStrategy
{
    public:
        virtual int solutionCost(std::vector<int> configuration) = 0;
};
