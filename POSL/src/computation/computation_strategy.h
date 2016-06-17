#pragma once

#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../packing/computation_strategy_uncoder.h"

class ComputationStrategy
{
    public:
        ComputationStrategy(std::string name, std::string code);

        void Instantiate(vector<string> & om_instances,
                         vector<string> & och_instances,
                         std::shared_ptr<Benchmark> bench,
                         shared_ptr<SearchProcessParamsStruct> psp_params);
        std::shared_ptr<Solution> execute(std::shared_ptr<PSP> psp);

        std::shared_ptr<CompoundModule> GetCompoundModule() { return module; }

        std::string TAG;

    private:
        std::string cs_code;
        std::shared_ptr<CompoundModule> module;
        ComputationStrategyUncoder cs_uncoder;
};
