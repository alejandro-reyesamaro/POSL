#include "../random_generator.h"

#include <chrono>

using namespace std;

RandomGenerator::RandomGenerator(int base_seed)
    : generator(chrono::system_clock::now().time_since_epoch().count() * (base_seed + 1))
{}

RandomGenerator::RandomGenerator()
    : generator(chrono::system_clock::now().time_since_epoch().count())
{}

int RandomGenerator::next_int(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

