#pragma once

#include "../../data/computation_data.h"
#include "../../modules/compound_module.h"
#include <thread>

class Executer
{
    public:
        Executer(CompoundModule * _M);
        void execute(PSP *psp, ComputationData * input);
        ComputationData * GetOutput();

    private:
        ComputationData * output;
        CompoundModule * M;
};
