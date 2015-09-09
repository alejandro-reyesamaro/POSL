#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom(std::vector<Domain> domains)
    : rPair(std::make_shared<DecisionPair>(std::make_shared<Solution>(domains), std::make_shared<Solution>(domains))),
      rand()
{}

std::shared_ptr<DecisionPair> NeighborSelectingRandom::select(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> V)
{
    int neighSize = V->size();
    int index = rand.NextInt(0, neighSize);
    rPair->update(psp->GetCurrentSolution()->GetConfiguration(), V->neighborAt(index));
    return rPair;
    //return make_shared<DecisionPair(psp->GetCurrentSolution(), make_shared<Solution(psp->GetBenchmark()->Domains(), V->neighborAt(index)));
}
