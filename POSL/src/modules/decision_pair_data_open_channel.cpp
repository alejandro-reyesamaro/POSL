#include "decision_pair_data_open_channel.h"
#include "../packing/packers/decision_pair_packer.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

DecisionPairDataOpenChannel::DecisionPairDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      pair_data(make_shared<DecisionPair>(make_shared<Solution>(_bench->Domains()), make_shared<Solution>(_bench->Domains())))
{}

int DecisionPairDataOpenChannel::dataID()
{
    return DECISIONPAIR_PACKING_ID;
}

string DecisionPairDataOpenChannel::codeToSend()
{
    return string(OCH_DECISIONPAIR_TOK) + "(" + name + ")";
}

shared_ptr<ComputationData> DecisionPairDataOpenChannel::unpackMessage(int * buffer, shared_ptr<PSP>)
{
    /*
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
    */
    pair_data->updateFromPack(buffer);
    return pair_data;
}
