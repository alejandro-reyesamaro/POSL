#pragma once

#include "../modules/operation_module.h"

class OM_V_AllPermutations_Uncoder
{
    public:
        OM_V_AllPermutations_Uncoder();
        std::shared_ptr<OperationModule> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
