#include "om_first_improvement_selection.h"

#include <iostream>
using namespace std;

OM_FirstImprovementSelection::OM_FirstImprovementSelection()
    : search_strategy(new NeighborSelectingFirstImprovement())
{}

DecisionPair * OM_FirstImprovementSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    DecisionPair * result = search_strategy->select(psp, input);
    return result;
}

string OM_FirstImprovementSelection::codeToSend()
{
    return "C2";
}
