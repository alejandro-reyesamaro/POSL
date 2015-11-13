#include "open_channel.h"

using namespace std;

OpenChannel::OpenChannel(std::string _name)
    : name(name),
      conn_tag("")
{}

shared_ptr<HashMap<string, string>> OpenChannel::GetConnections()
{
    shared_ptr<HashMap<string, string>> conns (make_shared<HashMap<string, string>>());
    conns->insert(name, conn_tag);
    return conns;
}

void OpenChannel::UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table)
{
    conn_tag = connections_table->mapOf(name);
}
