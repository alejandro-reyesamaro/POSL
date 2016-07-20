#include "neighborhood_last_data_open_channel.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/neighborhood.h"
#include "../tools/tokens_definition.h"

using namespace std;

NeighborhoodLastDataOpenChannel::NeighborhoodLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      received_data(nullptr)
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

shared_ptr<ComputationData> NeighborhoodLastDataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        return received_data;
    }
    else return nullptr;
}
