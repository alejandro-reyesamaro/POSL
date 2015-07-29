#include "om_one_element_changed_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"

#include <iostream>

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(){}

ComputationData * OM_OneElementChangedNeighborhood::execute(PSP *psp, ComputationData * input)
{
    //cout << "OneChange..." << endl;
    Neighborhood * V = new OneElementChangedNeighborhood((Solution *) input);
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}
