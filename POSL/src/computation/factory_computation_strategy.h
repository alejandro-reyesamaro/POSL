#pragma once

#include "../modules/compound_module.h"

class FactoryComputationStrategy
{
    public:
        virtual CompoundModule * buildModule() = 0;
};
