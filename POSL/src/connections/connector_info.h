#pragma once

#include <string>

enum ConnectionType { OUTLET, JACK };

struct ConnectorInfo
{
    public:
        std::string name;
        ConnectionType connectiopn_type;
};
