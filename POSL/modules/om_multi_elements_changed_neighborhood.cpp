#include "om_multi_elements_changed_neighborhood.h"
#include "data/multi_elements_changed_neighborhood.h"
#include <iostream>

OM_MultiElementsChangedNeighborhood::OM_MultiElementsChangedNeighborhood(){}

ComputationData * OM_MultiElementsChangedNeighborhood::execute(PSP *psp, ComputationData * input)
{
    //cout << "MultiChanges..." << endl;
    Neighborhood * V = new MultiElementsChangedNeighborhood((Solution *) input);
    return V;
}
