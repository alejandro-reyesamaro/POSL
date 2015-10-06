#pragma once

#include "../operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(std::shared_ptr<Operator> _op);

        virtual std::string Tag() {return "cm_GC"; }

    protected:
        std::shared_ptr<Operator> op;
};
