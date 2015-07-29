#include "om_random_selection.h"
#include "../data/decision_pair.h"
#include "../data/neighborhood.h"

OM_RandomSelection::OM_RandomSelection()
    : search_strategy(new NeighborSelectingRandom())
{}

ComputationData * OM_RandomSelection::execute(PSP *psp, ComputationData * input)
{
    Neighborhood * V = (Neighborhood *) input;
    DecisionPair * p = search_strategy->select(psp, V);
    return p;
}

string OM_RandomSelection::codeToSend()
{
    return "C1";
}
