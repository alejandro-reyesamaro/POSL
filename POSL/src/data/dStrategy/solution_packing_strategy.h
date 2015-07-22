#pragma once

#include "packing_strategy.h"

class SolutionPackingStrategy : public PackingStrategy
{
    public:
        SolutionPackingStrategy(vector<int> _config);
        vector<int> pack();
        int BodySize();
        vector<int> body();

    private:
        vector<int> configuration;
};
