#pragma once

#include "../operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(std::shared_ptr<Operator> _op);

        virtual std::string Tag() { return "cm_GC"; }

        std::shared_ptr<HashMap<std::string, std::string>> GetConnections();
        void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table);

    protected:
        std::shared_ptr<Operator> op;
};
