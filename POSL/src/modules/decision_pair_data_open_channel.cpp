#include "decision_pair_data_open_channel.h"
#include "../data/dStrategy/decision_pair_packing_strategy.h"
#include "../tools/tools.h"

#include <iostream>
using namespace std;

DecisionPairDataOpenChannel::DecisionPairDataOpenChannel()
{
}

int DecisionPairDataOpenChannel::dataTag()
{
    return DECISIONPAIR_PACKING_ID;
}

ComputationData * DecisionPairDataOpenChannel::unpackMessage(int * buffer, PSP * psp)
{
    cout << "unpacking message" << endl;

    // | ID |
    int id = buffer[0];

    // | conf_size |
    int conf_size = buffer[1];

    // | configuration 1|
    string pack_current_str = Tools::int2str(conf_size)+"[ ";
    for(int i = 0; i < conf_size; i++)
        pack_current_str += Tools::int2str(buffer[i+2]) + " ";
    pack_current_str += " ]";

    cout << pack_current_str << endl;

    DecisionPair * rPair = DecisionPairPackingStrategy::unpack(buffer, psp->GetBenchmark()->Domains());
    cout << "message unpacked: " << rPair->GetCurrent()->configurationToString() << endl;
    return rPair;
}
