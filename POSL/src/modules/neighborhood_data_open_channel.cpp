#include "neighborhood_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../data/from_pack_neighborhood.h"
#include "../tools/tokens_definition.h"

using namespace std;

NeighborhoodDataOpenChannel::NeighborhoodDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench)
{}

int NeighborhoodDataOpenChannel::dataID()
{
    return NEIGHBORHOOD_PACKING_ID;
}

string NeighborhoodDataOpenChannel::codeToSend()
{
    return string(OCH_NEIGHBORHOOD_TOK) + "(" + name + ")";
}

shared_ptr<ComputationData> NeighborhoodDataOpenChannel::unpackMessage(int * buffer, shared_ptr<PSP>)
{
    return make_shared<FromPackNeighborhood>(buffer);
}
