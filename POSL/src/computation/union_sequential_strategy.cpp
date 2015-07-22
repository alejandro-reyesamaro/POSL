#include "union_sequential_strategy.h"
#include "../data/neighborhood.h"
#include "../data/union_neighborhood.h"

#include <iostream>

UnionSequentialStrategy::UnionSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * UnionSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    Neighborhood * v1 = (Neighborhood *)M1->execute(psp, input);
    Neighborhood * v2 = (Neighborhood *)M2->execute(psp, input);
    return new UnionNeighborhood((Solution *)input, v1, v2);
}
