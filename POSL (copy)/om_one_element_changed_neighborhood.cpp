#include "om_one_element_changed_neighborhood.h"
#include "one_element_changed_neighborhood.h"

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(){}

ComputationData * OM_OneElementChangedNeighborhood::execute(Benchmark * bench, ComputationData * input)
{
    Neighborhood * V = new OneElementChangedNeighborhood((Solution *) input);
    return V;
}
