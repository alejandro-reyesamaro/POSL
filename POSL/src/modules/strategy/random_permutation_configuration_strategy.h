#pragma once
#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

class RandomPermutationConfigurationStrategy
{
    public:
        RandomPermutationConfigurationStrategy(int N);

        std::vector<int> generate();

    private:
        std::vector<int> config;
};
