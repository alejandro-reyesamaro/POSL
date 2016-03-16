#include "decision_pair_last_data_open_channel.h"
#include "../packing/packers/decision_pair_packer.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

DecisionPairLastDataOpenChannel::DecisionPairLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      pair_data(make_shared<DecisionPair>(make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension()),
                                          make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension())))

{}

int DecisionPairLastDataOpenChannel::dataID()
{
    return DECISIONPAIR_PACKING_ID;
}

string DecisionPairLastDataOpenChannel::codeToSend()
{
    return string(OCH_DECISIONPAIR_LAST_TOK) + "(" + name + ")";
}

std::shared_ptr<ComputationData> DecisionPairLastDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    pair_data->updateFromPack(buffer);
    return pair_data;
}

