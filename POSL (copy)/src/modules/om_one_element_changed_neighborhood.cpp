#include "om_one_element_changed_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"

#include <iostream>

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(){}

Neighborhood * OM_OneElementChangedNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Neighborhood * V = new OneElementChangedNeighborhood(input);
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}
