#pragma once

#include "../data/seed.h"
#include "matrix.h"
#include "random_generator.h"

#include <random>
#include <math.h>

class Randomizer
{
    public:
        Randomizer(int configuration_size);
        int NextInt(int min, int max);
        std::vector<std::vector<int>> generate_multichanges(int card_changes);
        std::vector<std::vector<int>> generate_multichanges();
        void vector_shuffle(std::vector<int> & vec);
        void vector_shuffle(std::vector<int> & vec, int _begin, int _end);

    private:
        RandomGenerator r_generator;
        int dim;
        Matrix indexes;
};
