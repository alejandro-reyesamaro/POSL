#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom()
    : rand (new Randomizer())
{}

DecisionPair * NeighborSelectingRandom::select(PSP *psp, Neighborhood * V)
{
    Solution * current_solution = psp->GetCurrentSolution();

    int neighSize = V->size();
    int index = rand->NextInt(0, neighSize);

    Solution * new_solution = new Solution(psp->GetBenchmark()->Domains(), V->operator[](index));
    DecisionPair * p = new DecisionPair(current_solution, new_solution);
    return p;
}
