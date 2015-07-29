#pragma once

#include "../modules/compound_module.h"
#include "uncode_sequential_grouper_strategy.h"
#include "uncode_parallel_grouper_strategy.h"
#include "uncode_operation_module_strategy.h"

class UncodeCompoundModuleStrategy
{
    public:
        UncodeCompoundModuleStrategy();
        CompoundModule * uncode(string code);    
};
