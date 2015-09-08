#include "om_random_selection.h"
#include "../data/decision_pair.h"
#include "../data/neighborhood.h"

OM_RandomSelection::OM_RandomSelection(shared_ptr<Benchmark> bench)
    : search_strategy(new NeighborSelectingRandom(bench->Domains()))
{}

shared_ptr<DecisionPair> OM_RandomSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

string OM_RandomSelection::codeToSend()
{
    return "C1";
}
