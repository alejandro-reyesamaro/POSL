#include "rho_sequential_strategy.h"

#include <iostream>
using namespace std;

RhoSequentialStrategy::RhoSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, float _rho)
    : M1(_M1),
      M2(_M2),
      rho(_rho),
      rand(),
      output1(nullptr),
      output2(nullptr)
{}

shared_ptr<ComputationData> RhoSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    output1 = M1->execute(psp, input);
    output2 = M2->execute(psp, input);
    if (output1 == nullptr) return output2;
    if (output2 == nullptr) return output1;
    int k = rand.NextInt(1,10);
    return (k <= rho*10) ? output1 : output2;
}
