#pragma once

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

class RandomGolombValidGenerationStrategy
{
    public:
        RandomGolombValidGenerationStrategy(int _order, int _length);

        std::vector<int> generate(shared_ptr<Randomizer> rand);

    private:
        int order, length;
        std::vector<int> config;
        std::vector<int> possible_measures;
};
