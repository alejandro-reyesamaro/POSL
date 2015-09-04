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
            Benchmark *_bench,
            AOM_FirstConfigurationGeneration * first_conf_generation,
            AOM_NeighborhoodFunction * neighborhood_function,
            AOM_SelectionFunction * selection_function,
            AOM_DecisionFunction * decision_fucntion,
            int loops_main_cycle
        );

        CompoundModule * buildModule();

    private:
        CompoundModule * final_module;
};
