#include "min_sequential_strategy.h"
#include "min_crit_comparison.h"

#include <iostream>
using namespace std;

MinSequentialStrategy::MinSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * MinSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    ComputationData * r1 = M1->execute(psp, input);
    ComputationData * r2 = M2->execute(psp, input);

    if (r1 == NULL) return r2;
    if (r2 == NULL) return r1;

    MinCritComparison * mincrit = new MinCritComparison();
    return mincrit->getMin(r1, r2, psp);
}
