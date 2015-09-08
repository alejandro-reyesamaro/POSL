#pragma once

#include "factory_computation_strategy.h"
#include "../modules/aom_first_configuration_generation.h"
#include "../modules/aom_neighborhood_function.h"
#include "../modules/aom_selection_function.h"
#include "../modules/aom_decision_function.h"

class FactoryComputationStrategy_Trivial : public FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy_Trivial
        (
            shared_ptr<Benchmark>_bench,
            shared_ptr<AOM_FirstConfigurationGeneration> first_conf_generation,
            shared_ptr<AOM_NeighborhoodFunction> neighborhood_function,
            shared_ptr<AOM_SelectionFunction> selection_function,
            shared_ptr<AOM_DecisionFunction> decision_fucntion,
            int loops_main_cycle
        );

        shared_ptr<CompoundModule> buildModule();

    private:
        shared_ptr<CompoundModule> final_module;
};
