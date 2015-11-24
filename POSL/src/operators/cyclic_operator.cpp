#include "cyclic_operator.h"
#include "strategy/cyclic_sequential_strategy.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

CyclicOperator::CyclicOperator(shared_ptr<CompoundModule> _M1, shared_ptr<BooleanExpression> _ex)
    : UnaryOperator(_M1, make_shared<CyclicSequentialStrategy>(_M1, _ex)),
      ex(_ex)
{}

string CyclicOperator::codeToSend()
{
    return string(OP_CYCLIC_TOK) + " (" + ex->codeToSend() + ") " + M1 ->codeToSend();
}

vector<ConnectorInfo> CyclicOperator::Jacks()
{
    return M1->Jacks();
}

vector<ConnectorInfo> CyclicOperator::Outlets()
{
    return M1->Outlets();
}

void CyclicOperator::connect(ConnectorInfo connector, int procID)
{
    M1->connect(connector, procID);
}
