#include "seed.h"
#include <chrono>

Seed::Seed()
{
}

double Seed::seed()
{
    return chrono::system_clock::now().time_since_epoch().count();
}

FactoryPacker * Seed::BuildPacker(){ throw "Not implemented yet"; }
