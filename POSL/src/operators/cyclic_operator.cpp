#include "cyclic_operator.h"
#include "strategy/cyclic_sequential_strategy.h"

#include <iostream>
using namespace std;

CyclicOperator::CyclicOperator(shared_ptr<CompoundModule> _M1, shared_ptr<BooleanExpression> _ex)
    : UnaryOperator(_M1, make_shared<CyclicSequentialStrategy>(_M1, _ex)),
      ex(_ex)
{}

string CyclicOperator::codeToSend()
{
    return "1 (" + ex->codeToSend() + ") " + M1 ->codeToSend();
}

shared_ptr<HashMap<string, string>> CyclicOperator::GetConnections()
{
    return M1->GetConnections();
}

void CyclicOperator::UpdateConnections(shared_ptr<HashMap<string, string>> connections_table)
{
    M1->UpdateConnections(connections_table);
}
