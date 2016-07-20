#include "open_channel.h"

using namespace std;

OpenChannel::OpenChannel(string _name)
    : name(_name)
{}

vector<ConnectorInfo> OpenChannel::Outlets()
{
    ConnectorInfo ci {name, OUTLET};
    vector<ConnectorInfo> vec;
    vec.push_back(ci);
    return vec;
}
