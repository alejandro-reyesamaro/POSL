#include "om_multi_sorted_changes_neighborhood.h"
#include "../data/multi_sorted_changes_neighborhood.h"

#include <iostream>

OM_MultiSortedChangesNeighborhood::OM_MultiSortedChangesNeighborhood(){}

Neighborhood * OM_MultiSortedChangesNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Neighborhood * V = new MultiSortedChangesNeighborhood(input);
    return V;
}

string OM_MultiSortedChangesNeighborhood::codeToSend()
{
    return "B4";
}
