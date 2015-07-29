#include "om_first_improvement_selection.h"

OM_FirstImprovementSelection::OM_FirstImprovementSelection()
    : search_strategy(new NeighborSelectingFirstImprovement())
{}

ComputationData * OM_FirstImprovementSelection::execute(PSP *psp, ComputationData * input)
{    
    return search_strategy->select(psp, (Neighborhood *)input);
}

string OM_FirstImprovementSelection::codeToSend()
{
    return "C2";
}
