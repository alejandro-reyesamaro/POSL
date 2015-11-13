#include "send_data_operator.h"
#include "strategy/send_data_sequential_strategy.h"

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

shared_ptr<HashMap<string, string>> SendDataOperator::GetConnections()
{
    shared_ptr<HashMap<string,string>> conns (make_shared<HashMap<string,string>>());
    conns->insert(name, conn_tag);
    return conns;
}

void SendDataOperator::UpdateConnections(shared_ptr<HashMap<string, string>> connections_table)
{
    conn_tag = connections_table->mapOf(name);
}
