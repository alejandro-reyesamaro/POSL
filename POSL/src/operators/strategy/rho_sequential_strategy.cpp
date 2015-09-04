#include "rho_sequential_strategy.h"

#include <iostream>
using namespace std;

RhoSequentialStrategy::RhoSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2, float _rho)
    : M1(_M1), M2(_M2), rho(_rho), rand(),
      output1(nullptr),
      output2(nullptr)
{}

ComputationData * RhoSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    output1 = M1->execute(psp, input);
    output2 = M2->execute(psp, input);
    if (output1 == NULL) return output2;
    if (output2 == NULL) return output1;
    int k = rand.NextInt(1,10);
    return (k <= rho*10) ? output1 : output2;
}
