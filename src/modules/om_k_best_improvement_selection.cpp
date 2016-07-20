#include "om_k_best_improvement_selection.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_KBestImprovementSelection::OM_KBestImprovementSelection(shared_ptr<Benchmark> bench, int k)
    : search_strategy(std::make_shared<NeighborSelectingKBestImprovement>(bench->Variable_Domain(), bench->Dimension(), k))
{}

shared_ptr<DecisionPair> OM_KBestImprovementSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    //cout << "OM_SS" << endl;
    return search_strategy->select(psp, input);
}

string OM_KBestImprovementSelection::codeToSend()
{
    return OM_KBEST_IMPROVEMENT_SELECTION_TOK;
}

string OM_KBestImprovementSelection::Tag()
{
    return "KBest_Selection";
}
