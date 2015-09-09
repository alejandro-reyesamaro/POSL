#include "seed.h"
#include <chrono>

Seed::Seed()
{}

double Seed::seed()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
}

std::shared_ptr<FactoryPacker> Seed::BuildPacker(){ throw "Not implemented yet"; }
