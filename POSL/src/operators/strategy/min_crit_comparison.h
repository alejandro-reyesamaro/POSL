#pragma once

#include "../../data/computation_data.h"
#include "../../solver/psp.h"

class MinCritComparison
{
    public:
        MinCritComparison();
        shared_ptr<ComputationData> getMin(shared_ptr<ComputationData> d1, shared_ptr<ComputationData> d2, shared_ptr<PSP> psp);
};
