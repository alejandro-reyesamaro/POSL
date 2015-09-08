#include "om_best_improvement_tabu_selection.h"

#include <iostream>
using namespace std;

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection(shared_ptr<Benchmark> bench)
    : search_strategy(make_shared<NeighborSelectingBestImprovementTabu>(bench->Domains()))
{}

shared_ptr<DecisionPair> OM_BestImprovementTabuSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

string OM_BestImprovementTabuSelection::codeToSend()
{
    return "C4";
}
