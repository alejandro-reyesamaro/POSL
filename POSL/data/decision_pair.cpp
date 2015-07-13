#include "decision_pair.h"
#include "dStrategy/decision_pair_packing_strategy.h"

DecisionPair::DecisionPair(Solution *_current, Solution *_found)
    : current(_current), found(_found), packing_strategy(new DecisionPairPackingStrategy(this))
{}

bool DecisionPair::equals()
{
    return current->equal(found);
}

Solution * DecisionPair::GetCurrent()
{
    return current;
}

Solution * DecisionPair::GetFound()
{
    return found;
}

int * DecisionPair::pack()
{
    return packing_strategy->pack();
}

int DecisionPair::bodySize()
{
    return packing_strategy->BodySize();
}

int * DecisionPair::body()
{
    return packing_strategy->body();
}
