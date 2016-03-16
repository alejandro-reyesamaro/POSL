#include "neighbor_selecting_random.h"

using namespace std;

NeighborSelectingRandom::NeighborSelectingRandom(shared_ptr<Domain> domain, int dimension)
    : rPair(std::make_shared<DecisionPair>(make_shared<Solution>(domain, dimension), make_shared<Solution>(domain, dimension)))
{}

shared_ptr<DecisionPair> NeighborSelectingRandom::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    int neighSize = V->size();
    int index = psp->GetRandomizer()->NextInt(0, neighSize);
    rPair->update(psp->GetCurrentSolution()->get_conf_by_ref(), V->neighborAt(index));
    return rPair;
}
