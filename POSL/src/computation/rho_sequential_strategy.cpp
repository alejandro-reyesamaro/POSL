#include "rho_sequential_strategy.h"

#include <iostream>
using namespace std;

RhoSequentialStrategy::RhoSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2, float _rho)
    : M1(_M1), M2(_M2), rho(_rho), rand()
{}

ComputationData * RhoSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    //cout << "Inside Rho Operator (strategy)" << endl;
    int k = rand.NextInt(1,10);
    ComputationData * result = (k <= rho*10) ? M1->execute(psp, input) : M2->execute(psp, input);
    //cout << "Inside Rho Operator (strategy) - DONE" << endl;
    return result;
}
