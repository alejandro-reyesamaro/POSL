#pragma once

#include "operation_module.h"

class OM_FirstImprovementSelection : public OperationModule
{
    public:
        OM_FirstImprovementSelection();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
