#pragma once

#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../packing/computation_strategy_uncoder.h"

class ComputationStrategy
{
    public:
        //!Constructor a eliminar
        //ComputationStrategy(std::shared_ptr<FactoryComputationStrategy> builder);

        //ComputationStrategy(std::string code, std::vector<std::string> om_instances, std::vector<std::string> och_instances, std::shared_ptr<Benchmark> bench);
        ComputationStrategy(std::string name, std::string code);

        void Instantiate(std::vector<std::string> om_instances, std::vector<std::string> och_instances, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<Solution> execute(std::shared_ptr<PSP> psp);

        std::shared_ptr<CompoundModule> GetCompoundModule() { return module; }

        std::string TAG;

    private:
        std::string cs_code;
        std::shared_ptr<CompoundModule> module;
        ComputationStrategyUncoder cs_uncoder;
};
