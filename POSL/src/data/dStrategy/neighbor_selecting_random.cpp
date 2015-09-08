#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom(vector<Domain> domains)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domains), make_shared<Solution>(domains))),
      rand (make_shared<Randomizer>())
{}

DecisionPair * NeighborSelectingRandom::select(PSP *psp, Neighborhood * V)
{
    int neighSize = V->size();
    int index = rand->NextInt(0, neighSize);
    rPair->update(psp->GetCurrentSolution()->GetConfiguration(), V->neighborAt(index));
    return rPair;
    //return make_shared<DecisionPair(psp->GetCurrentSolution(), make_shared<Solution(psp->GetBenchmark()->Domains(), V->neighborAt(index)));
}
