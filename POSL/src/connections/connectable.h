#pragma once

#include <memory>
#include <vector>

enum ConnectionType { OUTLET, JACK };

struct ConnectorInfo
{
    public:
        std::string name;
        ConnectionType connectiopn_type;
};

class Connectable
{
    public:
        //virtual std::shared_ptr<HashMap<std::string, POSL_Tag>> GetConnections() = 0;
        //virtual void UpdateConnections(std::shared_ptr<HashMap<std::string, POSL_Tag>> connections_table) = 0;
        virtual std::vector<ConnectorInfo> Jacks() = 0;
        virtual std::vector<ConnectorInfo> Outlets() = 0;
        virtual void connect(ConnectorInfo connector, int procID) = 0;
};
