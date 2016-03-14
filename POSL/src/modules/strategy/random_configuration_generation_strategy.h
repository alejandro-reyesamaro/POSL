#pragma once

/**
 * POSL
 *
 * \file random_configuration_generation_strategy.h
 * \brief Class to generate random configurations (Solutions)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../data/seed.h"
#include "../../tools/randomizer.h"

//#include <random>

/*!
 * \class RandomConfigurationGenerationStrategy random_configuration_generation_strategy.h
 * \brief Class to generate random configurations (Solutions)
 */
class RandomConfigurationGenerationStrategy
{
    public:
        RandomConfigurationGenerationStrategy(int configuration_size);

        std::vector<int> generate(shared_ptr<Randomizer> rand, std::vector<Domain> domains);

    private:
        std::vector<int> config;
};
