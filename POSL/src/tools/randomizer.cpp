#include "randomizer.h"

using namespace std;

Randomizer::Randomizer()
    : seed(),
      generator(seed.seed())
{
}

int Randomizer::NextInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    //distribution(make_shared<std::uniform_int_distribution<int>>(min, max));
    return distribution(generator);
}
