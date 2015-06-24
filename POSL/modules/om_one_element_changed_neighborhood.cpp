#include "om_one_element_changed_neighborhood.h"
#include "data/one_element_changed_neighborhood.h"

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(){}

ComputationData * OM_OneElementChangedNeighborhood::execute(PSP *psp, ComputationData * input)
{
    Neighborhood * V = new OneElementChangedNeighborhood((Solution *) input);
    return V;
}
