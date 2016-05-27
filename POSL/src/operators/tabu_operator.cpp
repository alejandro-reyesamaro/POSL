#include "tabu_operator.h"
#include "../tools/tokens_definition.h"
#include "../modules/open_channel.h"
#include "strategy/tabu_och_sequential_strategy.h"
#include "strategy/tabu_sequential_strategy.h"

#include <iostream>

using namespace std;

shared_ptr<SequentialExecutionStrategy> chose_sequential_strategy(shared_ptr<CompoundModule> _M1)
{
    if(_M1->Tag() == TAGOCh)
        return make_shared<TabuOChSequentialStrategy>(static_pointer_cast<OpenChannel>(_M1));
    else
        return make_shared<TabuSequentialStrategy>(_M1);
}

TabuOperator::TabuOperator(shared_ptr<CompoundModule> _M1)
    : UnaryOperator(_M1, chose_sequential_strategy(_M1))
{}

string TabuOperator::codeToSend()
{
    return string(OP_TABU_TOK) + " " + M1->codeToSend();
}

/*
shared_ptr<SendDataSequentialStrategy> TabuOperator::CastMyStrategy()
{
    return static_pointer_cast<SendDataSequentialStrategy>(seq_strategy);
}
*/

vector<ConnectorInfo> TabuOperator::Jacks()
{
    return M1->Jacks();
}

vector<ConnectorInfo> TabuOperator::Outlets()
{
    return M1->Outlets();
}

void TabuOperator::connect(ConnectorInfo connector, int procID)
{
    M1->connect(connector, procID);
}
