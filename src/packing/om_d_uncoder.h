#pragma once

#include "../modules/operation_module.h"

class OM_D_Uncoder
{
    public:
        OM_D_Uncoder();
        std::shared_ptr<OperationModule> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
