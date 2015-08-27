#include "om_one_sorted_change_neighborhood.h"
#include "../data/one_sorted_change_neighborhood.h"

#include <iostream>

OM_OneSortedChangeNeighborhood::OM_OneSortedChangeNeighborhood(){}

Neighborhood * OM_OneSortedChangeNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Neighborhood * V = new OneSortedChangeNeighborhood(input);
    return V;
}

string OM_OneSortedChangeNeighborhood::codeToSend()
{
    return "B5";
}
