#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom(vector<Domain> domains)
    : rPair(new DecisionPair(new Solution(domains), new Solution(domains))),
      rand (new Randomizer())
{}

DecisionPair * NeighborSelectingRandom::select(PSP *psp, Neighborhood * V)
{
    int neighSize = V->size();
    int index = rand->NextInt(0, neighSize);
    rPair->update(psp->GetCurrentSolution()->GetConfiguration(), V->neighborAt(index));
    return rPair;
    //return new DecisionPair(psp->GetCurrentSolution(), new Solution(psp->GetBenchmark()->Domains(), V->neighborAt(index)));
}
