#include "decision_pair_first_data_open_channel.h"
#include "../packing/packers/decision_pair_packer.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

DecisionPairFirstDataOpenChannel::DecisionPairFirstDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      pair_data(make_shared<DecisionPair>(make_shared<Solution>(_bench->Domains()), make_shared<Solution>(_bench->Domains())))
{}

int DecisionPairFirstDataOpenChannel::dataID()
{
    return DECISIONPAIR_PACKING_ID;
}

string DecisionPairFirstDataOpenChannel::codeToSend()
{
    return string(OCH_DECISIONPAIR_FIRST_TOK) + "(" + name + ")";
}

std::shared_ptr<ComputationData> DecisionPairFirstDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    if (!ContainsInformation())
    {
        pair_data->updateFromPack(buffer);
        return pair_data;
    }
}