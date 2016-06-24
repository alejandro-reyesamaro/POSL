#include "neighborhood_last_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../tools/tokens_definition.h"

using namespace std;

NeighborhoodLastDataOpenChannel::NeighborhoodLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench)
{}

int NeighborhoodLastDataOpenChannel::dataID()
{
    return NEIGHBORHOOD_PACKING_ID;
}

string NeighborhoodLastDataOpenChannel::codeToSend()
{
    return string(OCH_NEIGHBORHOOD_LAST_TOK) + "(" + name + ")";
}

void NeighborhoodLastDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    received_data = make_shared<FromPackNeighborhood>(buffer);
}
