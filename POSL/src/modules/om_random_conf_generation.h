#pragma once

/**
 * POSL
 *
 * \file om_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"
#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_configuration_generation_strategy.h"

/*!
 * \class OM_RandomConfGeneration om_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration
 */
class OM_RandomConfGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomConfGeneration(shared_ptr<Benchmark> bench);

        shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();

    private:
        shared_ptr<RandomConfigurationGenerationStrategy> rconf_strategy;
        shared_ptr<Solution> rsolution;
};
