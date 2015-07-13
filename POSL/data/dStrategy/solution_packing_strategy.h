#pragma once

#include "packing_strategy.h"

#include <vector>

using namespace std;

class SolutionPackingStrategy : public PackingStrategy
{
    public:
        SolutionPackingStrategy(vector<int> _config);
        int * pack();
        int BodySize();
        int * body();

    private:
        vector<int> configuration;
};
