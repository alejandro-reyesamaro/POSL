#pragma once

#include "packing_strategy.h"
#include "../solution.h"
#include "../domain.h"

class SolutionPackingStrategy : public PackingStrategy
{
    public:
        SolutionPackingStrategy(vector<int> _config);
        vector<int> pack();
        int BodySize();
        vector<int> body();

        static Solution * unpack(int * pack, vector<Domain> domains);

    private:
        vector<int> configuration;
};
