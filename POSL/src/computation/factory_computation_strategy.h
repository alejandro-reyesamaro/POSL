#pragma once

#include "../modules/compound_module.h"

class FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy(Benchmark * _bench);

        virtual CompoundModule * buildModule() = 0;

    protected:
        Benchmark * bench;
};
