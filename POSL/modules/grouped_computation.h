#pragma once

#include "operators/operator.h"

class GroupedComputation : public CompoundModule
{
    public:
        GroupedComputation(Operator * _op);

    protected:
        Operator * op;
};
