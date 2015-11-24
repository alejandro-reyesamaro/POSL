#include "om_first_improvement_selection.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_FirstImprovementSelection::OM_FirstImprovementSelection(shared_ptr<Benchmark> bench)
    : search_strategy(std::make_shared<NeighborSelectingFirstImprovement>(bench->Domains()))
{}

shared_ptr<DecisionPair> OM_FirstImprovementSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{    
    return search_strategy->select(psp, input);
}

string OM_FirstImprovementSelection::codeToSend()
{
    return OM_FIRST_IMPROVEMENT_SELECTION_TOK;
}

string OM_FirstImprovementSelection::Tag()
{
    return "First_Selection";
}
