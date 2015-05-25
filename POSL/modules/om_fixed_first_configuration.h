#pragma once

#include "modules/operation_module.h"

class OM_FixedFirstConfiguration : public OperationModule
{
    public:
        OM_FixedFirstConfiguration();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
