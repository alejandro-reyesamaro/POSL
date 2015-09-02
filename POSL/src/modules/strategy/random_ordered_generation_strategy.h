#pragma once

/**
 * POSL
 *
 * \file random_ordered_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but ordered
 * \author Alejandro Reyes
 * \date 2015-08-10
 */

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

#include <random>

/*!
 * \class RandomOrderedGenerationStrategy random_ordered_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but ordered
 */
class RandomOrderedGenerationStrategy
{
    public:
        RandomOrderedGenerationStrategy(int configuration_size);

        //! Generates a random configuration
        /*!
        * \param size Configuration size
        * \param max Maximum value
        * \return A random ordered configuration (Solution)
        */
        vector<int> *generate(int max);

    private:        
        void place (int a, int b, int pos_1, int pos_2);

        vector<int> config;
        Randomizer rand;
        vector<Domain> domains;
};
