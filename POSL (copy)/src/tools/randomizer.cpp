#include "randomizer.h"

Randomizer::Randomizer()
    : generator((new Seed())->seed())
{
}

int Randomizer::NextInt(int min, int max)
{
    distribution = new uniform_int_distribution<int>(min, max);
    return distribution->operator ()(generator);
}
