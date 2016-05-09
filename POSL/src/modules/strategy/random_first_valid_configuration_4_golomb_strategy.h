#pragma once

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

class RandomFirstValidConfiguration4GolombStrategy
{
    public:
        RandomFirstValidConfiguration4GolombStrategy();

        std::vector<int> generate(shared_ptr<Randomizer> rand, int subsum, int n, int set_size);

    private:
        std::vector<int> config;
};
