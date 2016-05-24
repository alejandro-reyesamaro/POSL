#pragma once

#include "../data/seed.h"
#include "matrix.h"
#include "random_generator.h"

#include <random>
#include <math.h>

class Randomizer
{
    public:
        Randomizer(int configuration_size, int base_seed);
        int NextInt(int min, int max);
        bool bernoulli(float p);
        std::vector<std::vector<int>> generate_multichanges(int card_changes);
        std::vector<std::vector<int>> generate_multichanges();
        void vector_shuffle(std::vector<int> & vec);
        void vector_shuffle(std::vector<int> & vec, int _begin, int _end);

    private:
        RandomGenerator r_generator;
        std::default_random_engine generator;
        int dim;
        Matrix indexes;
};
