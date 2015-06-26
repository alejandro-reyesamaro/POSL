#include "rho_sequential_strategy.h"
#include <iostream>

RhoSequentialStrategy::RhoSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2, float _rho)
    : M1(_M1), M2(_M2), rho(_rho), generator(chrono::system_clock::now().time_since_epoch().count()), distribution(1,10)

{}

ComputationData * RhoSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    int k = distribution(generator);
    return (k <= rho*10) ? M1->execute(psp, input) : M2->execute(psp, input);
}
