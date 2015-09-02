#pragma once
#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

#include <random>

class RandomPermutationConfigurationStrategy
{
    public:
        //! Constructor
        RandomPermutationConfigurationStrategy();

        Solution * generate(vector<Domain> domains);
};
