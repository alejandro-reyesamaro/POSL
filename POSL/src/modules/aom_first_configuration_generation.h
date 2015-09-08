#pragma once

#include "operation_module.h"
#include "../data/solution.h"

class AOM_FirstConfigurationGeneration : public OperationModule
{
    public:
        AOM_FirstConfigurationGeneration(shared_ptr<Benchmark> bench);

        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        virtual shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input) = 0;

    protected:
        vector<Domain> domains;
};
