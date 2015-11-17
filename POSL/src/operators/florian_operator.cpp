#include "florian_operator.h"
#include "strategy/florian_sequential_strategy.h"

#include <iostream>
using namespace std;

FlorianOperator::FlorianOperator(shared_ptr<CompoundModule> _M1)
    : UnaryOperator(_M1, make_shared<FlorianSequentialStrategy>(_M1))
{}

string FlorianOperator::codeToSend()
{
    return "7 " + M1 ->codeToSend();
}

vector<ConnectorInfo> FlorianOperator::Jacks()
{
    return M1->Jacks();
}

vector<ConnectorInfo> FlorianOperator::Outlets()
{
    return M1->Outlets();
}

void FlorianOperator::connect(ConnectorInfo connector, int procID)
{
    M1->connect(connector, procID);
}
