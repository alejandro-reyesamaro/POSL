#include "om_multi_elements_changed_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"

#include <iostream>

OM_MultiElementsChangedNeighborhood::OM_MultiElementsChangedNeighborhood(){}

Neighborhood * OM_MultiElementsChangedNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Neighborhood * V = new MultiElementsChangedNeighborhood(input);
    return V;
}

string OM_MultiElementsChangedNeighborhood::codeToSend()
{
    return "B2";
}
