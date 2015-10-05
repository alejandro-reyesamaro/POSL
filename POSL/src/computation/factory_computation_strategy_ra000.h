#pragma once

#include "factory_computation_strategy.h"
#include "../modules/aom_first_configuration_generation.h"
#include "../modules/aom_neighborhood_function.h"
#include "../modules/aom_selection_function.h"
#include "../modules/aom_decision_function.h"

class FactoryComputationStrategy_RA000 : public FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy_RA000
        (
            std::shared_ptr<Benchmark> _bench,
            std::shared_ptr<AOM_FirstConfigurationGeneration> first_conf_generation,
            std::shared_ptr<AOM_NeighborhoodFunction> neighborhood_function,
            std::shared_ptr<AOM_SelectionFunction> selection_function,
            std::shared_ptr<AOM_DecisionFunction> decision_fucntion,
            int loops_main_cycle,
            int loops_restart_cycle
        );

        std::shared_ptr<CompoundModule> buildModule();

    private:
        std::shared_ptr<CompoundModule> final_module;
};
