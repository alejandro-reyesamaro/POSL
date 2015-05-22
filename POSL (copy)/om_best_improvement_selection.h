#pragma once

#include "operation_module.h"

class OM_BestImprovementSelection : public OperationModule
{
    public:
        OM_BestImprovementSelection();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
