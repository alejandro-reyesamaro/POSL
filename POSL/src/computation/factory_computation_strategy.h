#pragma once

#include "../modules/compound_module.h"

class FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy(std::shared_ptr<Benchmark> _bench, std::string tag);

        virtual std::shared_ptr<CompoundModule> buildModule() = 0;

        std::string TAG;

    protected:
        std::shared_ptr<Benchmark> bench;
};
