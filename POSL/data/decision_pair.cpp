#include "decision_pair.h"

DecisionPair::DecisionPair(Solution *_current, Solution *_found)
    : current(_current), found(_found)
{}

bool DecisionPair::equals()
{
    return current->equal(found);
}
