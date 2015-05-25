#pragma once

#include "data/solution.h"
#include "data/domain.h"
#include "data/seed.h"

class RandomConfigurationGenerationStrategy
{
    public:
        RandomConfigurationGenerationStrategy();
        Solution * generate(vector<Domain> domains, Seed * s);
};
