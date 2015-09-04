#pragma once

#include "factory_computation_strategy.h"
#include "../modules/aom_first_configuration_generation.h"
#include "../modules/aom_neighborhood_function.h"
#include "../modules/aom_selection_function.h"
#include "../modules/aom_decision_function.h"

class FactoryComputationStrategy_RA001 : public FactoryComputationStrategy
{
    public:
        FactoryComputationStrategy_RA001
        (
            Benchmark *_bench,
            AOM_FirstConfigurationGeneration * first_conf_generation,
            AOM_NeighborhoodFunction * neighborhood_function,
            AOM_SelectionFunction * selection_function_1,
            AOM_SelectionFunction * selection_function_2,
            AOM_DecisionFunction * decision_fucntion_1,
            AOM_DecisionFunction * decision_fucntion_2,
            float prob_op_rho_selection,
            int cost_op_cond_decision,
            int loops_main_cycle,
            int loops_restart_cycle
        );

        CompoundModule * buildModule();

    private:
        CompoundModule * final_module;
};
