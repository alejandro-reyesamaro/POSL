#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom()
    : rand (new Randomizer())
{}

DecisionPair * NeighborSelectingRandom::select(PSP *psp, Neighborhood * V)
{
    int neighSize = V->size();
    int index = rand->NextInt(0, neighSize);
    return new DecisionPair(psp->GetCurrentSolution(), new Solution(psp->GetBenchmark()->Domains(), V->operator[](index)));
}
