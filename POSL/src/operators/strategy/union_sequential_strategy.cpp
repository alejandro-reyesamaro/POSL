#include "union_sequential_strategy.h"

#include <iostream>

UnionSequentialStrategy::UnionSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2),
      v1(nullptr),
      v2(nullptr)
{}

ComputationData * UnionSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    v1 = (Neighborhood *)M1->execute(psp, input);
    v2 = (Neighborhood *)M2->execute(psp, input);

    if (v1 == nullptr) return v2;
    if (v2 == nullptr) return v1;

    return new UnionNeighborhood((Solution *)input, v1, v2);
}
