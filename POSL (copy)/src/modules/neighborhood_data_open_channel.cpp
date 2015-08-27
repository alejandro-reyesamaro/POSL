#include "neighborhood_data_open_channel.h"
#include "../data/dStrategy/neighborhood_packing_strategy.h"

#include "mpi.h"

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel()
{
}

int NeighborhoodDataOpenChannel::dataTag()
{
    return NEIGHBORHOOD_PACKING_ID;
}

ComputationData * NeighborhoodDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    Neighborhood * rV = NeighborhoodPackingStrategy::unpack(buffer);
    return rV;
}
