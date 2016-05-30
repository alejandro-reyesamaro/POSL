#include "om_first_improvement_global_tabu_selection.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_FirstImprovementGlobalTabuSelection::OM_FirstImprovementGlobalTabuSelection(shared_ptr<Benchmark> bench, float _eps)
    : search_strategy(make_shared<NeighborSelectingFirstImprovementGlobalTabu>(bench->Variable_Domain(), bench->Dimension())),
      eps(_eps)
{}

shared_ptr<DecisionPair> OM_FirstImprovementGlobalTabuSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input, eps);
}

string OM_FirstImprovementGlobalTabuSelection::codeToSend()
{
    return OM_FIRST_IMPROVEMENT_GLOBAL_TABU_SELECTION_TOK; //"OM_SS.FirstImprGT"
}

string OM_FirstImprovementGlobalTabuSelection::Tag()
{
    return "First_Selection(Global-Tabu)";
}
