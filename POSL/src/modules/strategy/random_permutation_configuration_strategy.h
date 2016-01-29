#pragma once
#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

class RandomPermutationConfigurationStrategy
{
    public:
        RandomPermutationConfigurationStrategy(int N);
        RandomPermutationConfigurationStrategy(int a, int b);

        std::vector<int> generate(std::shared_ptr<Seed>);

    private:
        std::vector<int> config;
};
