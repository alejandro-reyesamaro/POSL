#include "neighbor_selecting_random.h"

NeighborSelectingRandom::NeighborSelectingRandom(std::vector<Domain> domains)
    : rPair(std::make_shared<DecisionPair>(std::make_shared<Solution>(domains), std::make_shared<Solution>(domains)))
{}

std::shared_ptr<DecisionPair> NeighborSelectingRandom::select(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> V)
{
    int neighSize = V->size();
    int index = psp->GetRandomizer()->NextInt(0, neighSize);
    rPair->update(psp->GetCurrentSolution()->get_conf_by_ref(), V->neighborAt(index));
    return rPair;
}
