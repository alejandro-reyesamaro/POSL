#pragma once

#include "../operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(shared_ptr<Operator> _op);

    protected:
        shared_ptr<Operator> op;
};
