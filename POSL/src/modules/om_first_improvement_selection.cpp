#include "om_first_improvement_selection.h"

#include <iostream>
using namespace std;

OM_FirstImprovementSelection::OM_FirstImprovementSelection()
    : search_strategy(new NeighborSelectingFirstImprovement())
{}

ComputationData * OM_FirstImprovementSelection::execute(PSP *psp, ComputationData * input)
{
    //cout << "Inside OM First Impro" << endl;
    DecisionPair * result = search_strategy->select(psp, (Neighborhood *)input);
    //cout << "Inside OM First Impro - DONE" << endl;
    return result;
}

string OM_FirstImprovementSelection::codeToSend()
{
    return "C2";
}
