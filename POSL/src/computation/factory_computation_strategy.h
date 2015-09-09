#pragma once

#include "../modules/compound_module.h"

class FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy(std::shared_ptr<Benchmark> _bench);

        virtual std::shared_ptr<CompoundModule> buildModule() = 0;

    protected:
        std::shared_ptr<Benchmark> bench;
};
