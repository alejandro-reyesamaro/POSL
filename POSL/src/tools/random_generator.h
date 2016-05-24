#pragma once

#include <random>

class RandomGenerator
{
    public:
        RandomGenerator();
        RandomGenerator(int base_seed);
        int next_int(int min, int max);
        std::default_random_engine GetGenerator() { return generator; }

    private:
        std::default_random_engine generator;
};
