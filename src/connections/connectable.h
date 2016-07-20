#pragma once

#include "connector_info.h"

#include <memory>
#include <vector>

class Connectable
{
    public:
        //virtual std::shared_ptr<HashMap<std::string, POSL_Tag>> GetConnections() = 0;
        //virtual void UpdateConnections(std::shared_ptr<HashMap<std::string, POSL_Tag>> connections_table) = 0;
        virtual std::vector<ConnectorInfo> Jacks() = 0;
        virtual std::vector<ConnectorInfo> Outlets() = 0;
        virtual void connect(ConnectorInfo connector, int procID) = 0;
};
