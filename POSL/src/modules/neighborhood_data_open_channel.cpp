#include "neighborhood_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../data/from_pack_neighborhood.h"

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel(Benchmark * _bench)
    : DataOpenChannel(_bench)
{
}

int NeighborhoodDataOpenChannel::dataTag()
{
    return NEIGHBORHOOD_PACKING_ID;
}

ComputationData * NeighborhoodDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    return new FromPackNeighborhood(buffer);
}
