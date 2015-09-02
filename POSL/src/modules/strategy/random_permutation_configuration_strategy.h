#pragma once
#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

#include <random>

class RandomPermutationConfigurationStrategy
{
    public:
        RandomPermutationConfigurationStrategy(int N);

        vector<int> generate();

    private:
        vector<int> config;
};
