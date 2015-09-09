#pragma once

#include "../../data/computation_data.h"
#include "../../solver/psp.h"

class MinCritComparison
{
    public:
        MinCritComparison();
        std::shared_ptr<ComputationData> getMin(std::shared_ptr<ComputationData> d1, std::shared_ptr<ComputationData> d2, std::shared_ptr<PSP> psp);
};
