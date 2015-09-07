#pragma once

#include "../modules/compound_module.h"

class FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy(shared_ptr<Benchmark> _bench);

        virtual shared_ptr<CompoundModule> buildModule() = 0;

    protected:
        shared_ptr<Benchmark> bench;
};
