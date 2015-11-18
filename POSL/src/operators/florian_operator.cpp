#include "florian_operator.h"
#include "../tools/tools.h"

#include <iostream>
using namespace std;

FlorianOperator::FlorianOperator(int k, shared_ptr<CompoundModule> _M1)
    : UnaryOperator(_M1, make_shared<FlorianSequentialStrategy>(k, _M1))
{}

shared_ptr<FlorianSequentialStrategy> FlorianOperator::CastMyStrategy()
{
    return static_pointer_cast<FlorianSequentialStrategy>(seq_strategy);
}

string FlorianOperator::codeToSend()
{
    return "OP.Flo (" + Tools::int2str(CastMyStrategy()->GetIterations()) + ") " + M1 ->codeToSend();
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
