#pragma once

#include "../../data/computation_data.h"
#include "../../solver/psp.h"

class MinCritComparison
{
    public:
        MinCritComparison();
        ComputationData * getMin(ComputationData * d1, ComputationData * d2, PSP * psp);
};
