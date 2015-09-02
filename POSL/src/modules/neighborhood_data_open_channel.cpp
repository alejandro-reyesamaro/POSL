#include "neighborhood_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel()
{
}

int NeighborhoodDataOpenChannel::dataTag()
{
    return NEIGHBORHOOD_PACKING_ID;
}

ComputationData * NeighborhoodDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    Neighborhood * rV = NeighborhoodPacker::unpack(buffer);
    return rV;
}
