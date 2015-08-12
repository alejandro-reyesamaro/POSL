#include "om_one_sorted_change_neighborhood.h"
#include "../data/one_sorted_change_neighborhood.h"

#include <iostream>

OM_OneSortedChangeNeighborhood::OM_OneSortedChangeNeighborhood(){}

ComputationData * OM_OneSortedChangeNeighborhood::execute(PSP *psp, ComputationData * input)
{
    Neighborhood * V = new OneSortedChangeNeighborhood((Solution *) input);
    return V;
}

string OM_OneSortedChangeNeighborhood::codeToSend()
{
    return "B5";
}
