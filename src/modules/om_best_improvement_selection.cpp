#include "om_best_improvement_selection.h"
#include "../tools/tokens_definition.h"

using namespace std;

OM_BestImprovementSelection::OM_BestImprovementSelection(shared_ptr<Benchmark> bench)
    : search_strategy(make_shared<NeighborSelectingBestImprovement>(bench->Variable_Domain(), bench->Dimension()))
{}

shared_ptr<DecisionPair> OM_BestImprovementSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    return search_strategy->select(psp, input);
}

string OM_BestImprovementSelection::codeToSend()
{
    return OM_BEST_IMPROVEMENT_SELECTION_TOK;
}

string OM_BestImprovementSelection::Tag()
{
    return "Best_Selection";
}
