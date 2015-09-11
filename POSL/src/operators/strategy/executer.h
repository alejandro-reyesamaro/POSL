#pragma once

#include "../../data/computation_data.h"
#include "../../modules/compound_module.h"
#include <thread>

class Executer
{
    public:
        Executer(std::shared_ptr<CompoundModule> _M);

        void execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        std::shared_ptr<ComputationData> GetOutput();

    private:        
        std::shared_ptr<CompoundModule> M;
        std::shared_ptr<ComputationData> output;
};
