#include "send_data_operator.h"

#include <iostream>
using namespace std;

SendDataOperator::SendDataOperator(std::string _name, shared_ptr<CompoundModule> _M1)
    : UnaryOperator(_M1, make_shared<SendDataSequentialStrategy>(_M1)),
      name(_name),
      conn_tag("")
{}

string SendDataOperator::codeToSend()
{
    return M1->codeToSend();
}

vector<ConnectorInfo> SendDataOperator::Jacks()
{
    ConnectorInfo ci {name, JACK};
    vector<ConnectorInfo> vec;
    vec.push_back(ci);
    return vec;
}

vector<ConnectorInfo> SendDataOperator::Outlets()
{
    return M1->Outlets();
}

shared_ptr<SendDataSequentialStrategy> SendDataOperator::CastMyStrategy()
{
    return static_pointer_cast<SendDataSequentialStrategy>(seq_strategy);
}

void SendDataOperator::connect(ConnectorInfo connector, int procID)
{
    if(connector.name == name)
        CastMyStrategy()->addDestiny(procID);
    else
        M1->connect(connector, procID);
}
