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

#include <random>

/*!
 * \class RandomConfigurationGenerationStrategy random_configuration_generation_strategy.h
 * \brief Class to generate random configurations (Solutions)
 */
class RandomConfigurationGenerationStrategy
{
    public:
        //! Constructor
        RandomConfigurationGenerationStrategy();

        //! Generates a random configuration
        /*!
        * \param domains The sets of posibles values for the variables
        * \param seed A seed for the random generatos
        * \return A random configuration (Solution)
        */
        Solution * generate(vector<Domain> domains);

    private:
        Randomizer rand;
};
