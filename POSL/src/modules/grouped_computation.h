#pragma once

#include "../operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(std::shared_ptr<Operator> _op);

        virtual std::string Tag() { return "cm_GC"; }

        //! From Connectable
        std::vector<ConnectorInfo> Jacks() { return op->Jacks(); }
        std::vector<ConnectorInfo> Outlets() { return op->Outlets(); }
        void connect(ConnectorInfo connector, int procID) { op->connect(connector, procID); }

    protected:
        std::shared_ptr<Operator> op;
};
