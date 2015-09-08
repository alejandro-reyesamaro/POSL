#pragma once

#include "../../data/computation_data.h"
#include "../../modules/compound_module.h"
#include <thread>

class Executer
{
    public:
        Executer(shared_ptr<CompoundModule> _M);

        void execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        shared_ptr<ComputationData> GetOutput();

    private:
        shared_ptr<ComputationData> output;
        shared_ptr<CompoundModule> M;
};
