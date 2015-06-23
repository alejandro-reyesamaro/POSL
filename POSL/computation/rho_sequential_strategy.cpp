#include "rho_sequential_strategy.h"

#include <random>
#include <chrono>
#include <iostream>

RhoSequentialStrategy::RhoSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2, float _rho) : M1(_M1), M2(_M2), rho(_rho)
{
}

ComputationData * RhoSequentialStrategy::evaluate(Benchmark * bench, ComputationData * input)
{
    double seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(0, 10);
    float k = distribution(generator);
    return (k*10 < rho) ? M1->execute(bench, input) : M2->execute(bench, input);
}
