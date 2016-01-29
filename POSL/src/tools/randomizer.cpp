#include "randomizer.h"

using namespace std;

Randomizer::Randomizer()
    : generator(std::default_random_engine(make_shared<Seed>()->seed()))
{}

int Randomizer::NextInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    //distribution(make_shared<std::uniform_int_distribution<int>>(min, max));
    return distribution(generator);
}
