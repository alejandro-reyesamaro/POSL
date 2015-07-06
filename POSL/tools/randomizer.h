#pragma once

#include <random>
//#include <chrono>
#include "data/seed.h"
//#include <math.h>

using namespace std;

class Randomizer
{
    public:
        Randomizer();
        int NextInt(int min, int max);

    private:
        default_random_engine generator;
        uniform_int_distribution<int> * distribution;
};
