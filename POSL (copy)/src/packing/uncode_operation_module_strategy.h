#pragma once

#include "../modules/operation_module.h"

class UncodeOperationModuleStrategy
{
    public:
        UncodeOperationModuleStrategy();
        OperationModule * uncode(string code);
};
