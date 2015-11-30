#pragma once

#include <string>

enum ConnectionType { OUTLET, JACK };

struct ConnectorInfo
{
    public:
        std::string name;
        ConnectionType connectiopn_type;
        // No es factible por el momento
        //int type_id;
        static bool equal(ConnectorInfo & c1, ConnectorInfo & c2)
        {
            return (c1.name == c2.name && c1.connectiopn_type == c2.connectiopn_type);
        }
};
