#pragma once

#include "packing_strategy.h"

#include <vector>

using namespace std;

class SolutionPackingStrategy : public PackingStrategy
{
    public:
        SolutionPackingStrategy(vector<int> _config);
        int * pack();

    private:
        vector<int> configuration;
};
