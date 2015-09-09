#pragma once

#include <random>
#include "../data/seed.h"

class Randomizer
{
    public:
        Randomizer();
        int NextInt(int min, int max);

    private:
        Seed seed;
        std::default_random_engine generator;
        //std::shared_ptr<std::uniform_int_distribution<int>> distribution;
};
