#pragma once

#include "../modules/operation_module.h"

class OperationModuleSimulatedAnealingUncoder
{
    public:
        OperationModuleSimulatedAnealingUncoder();
        std::shared_ptr<OperationModule> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
