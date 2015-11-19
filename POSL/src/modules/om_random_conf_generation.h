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
#include "../data/seed.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_configuration_generation_strategy.h"

#define OM_RANDOM_CONFIG_GENERATION_TOK "OM_S.Rand"
/*!
 * \class OM_RandomConfGeneration om_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration
 */
class OM_RandomConfGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomConfGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<RandomConfigurationGenerationStrategy> rconf_strategy;
        std::shared_ptr<Solution> rsolution;
};
