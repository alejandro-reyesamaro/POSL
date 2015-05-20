#include "om_one_element_changed_neighborhood.h"
#include "one_element_changed_neighborhood.h"

shared_ptr<Neighborhood> OM_OneElementChangedNeighborhood::execute(shared_ptr<Benchmark> input)
{
    shared_ptr<Neighborhood> V = make_shared<OneElementChangedNeighborhood>(input->solution);
    return V;
}
