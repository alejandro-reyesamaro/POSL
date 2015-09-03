#include "om_random_selection.h"
#include "../data/decision_pair.h"
#include "../data/neighborhood.h"

OM_RandomSelection::OM_RandomSelection(Benchmark * bench)
    : search_strategy(new NeighborSelectingRandom(bench->Domains()))
{}

DecisionPair * OM_RandomSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    return search_strategy->select(psp, input);
}

string OM_RandomSelection::codeToSend()
{
    return "C1";
}
