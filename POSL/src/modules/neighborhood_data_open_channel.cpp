#include "neighborhood_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../data/from_pack_neighborhood.h"

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel(shared_ptr<Benchmark> _bench)
    : DataOpenChannel(_bench)
{
}

int NeighborhoodDataOpenChannel::dataTag()
{
    return NEIGHBORHOOD_PACKING_ID;
}

shared_ptr<ComputationData> NeighborhoodDataOpenChannel::unpackMessage(int * buffer, shared_ptr<PSP> psp)
{
    return make_shared<FromPackNeighborhood>(buffer);
}
