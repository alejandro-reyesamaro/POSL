#pragma once

#include "../tools/hash_map.h"

#include <memory>

class Connectable
{
    public:
        virtual std::shared_ptr<HashMap<std::string, std::string>> GetConnections() = 0;
        virtual void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table) = 0;
};
