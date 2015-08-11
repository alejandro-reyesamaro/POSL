#include "om_multi_sorted_changes_neighborhood.h"
#include "../data/multi_sorted_changes_neighborhood.h"
#include <iostream>

OM_MultiSortedChangesNeighborhood::OM_MultiSortedChangesNeighborhood(){}

ComputationData * OM_MultiSortedChangesNeighborhood::execute(PSP *psp, ComputationData * input)
{
    //cout << "MultiChanges..." << endl;
    Neighborhood * V = new MultiSortedChangesNeighborhood((Solution *) input);
    return V;
}

string OM_MultiSortedChangesNeighborhood::codeToSend()
{
    return "B4";
}
