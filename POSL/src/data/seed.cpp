#include "seed.h"
#include <chrono>
#include <cmath>

using namespace std;

Seed::Seed()
    : Seed(time(0))//abs(chrono::system_clock::now().time_since_epoch().count()))
{}

Seed::Seed(int _seed)
    : my_seed(_seed)
{}

std::shared_ptr<FactoryPacker> Seed::BuildPacker(){ throw "Not implemented yet"; }
