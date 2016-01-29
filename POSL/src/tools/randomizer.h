#pragma once

#include <random>
#include "../data/seed.h"

class Randomizer
{
    public:
        Randomizer();
        int NextInt(int min, int max);
        //void SetSeed(std::shared_ptr<Seed> posl_seed);

    private:
        //std::shared_ptr<Seed> seed;
        std::default_random_engine generator;
        //std::shared_ptr<std::default_random_engine> generator;
};
