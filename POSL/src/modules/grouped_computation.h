#pragma once

#include "../operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(std::shared_ptr<Operator> _op);

    protected:
        std::shared_ptr<Operator> op;
};
