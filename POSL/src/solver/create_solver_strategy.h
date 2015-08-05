#pragma once

#include "../modules/operation_module.h"

class CreateSolverStrategy
{
    public:
        virtual CompoundModule * create() = 0;
};
