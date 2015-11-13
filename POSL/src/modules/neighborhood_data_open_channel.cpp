#include "neighborhood_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../data/from_pack_neighborhood.h"

using namespace std;

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench)
{}

int NeighborhoodDataOpenChannel::dataTag()
{
    return NEIGHBORHOOD_PACKING_ID;
}

shared_ptr<ComputationData> NeighborhoodDataOpenChannel::unpackMessage(int * buffer, shared_ptr<PSP>)
{
    return make_shared<FromPackNeighborhood>(buffer);
}
