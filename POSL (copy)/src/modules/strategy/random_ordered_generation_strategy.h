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
        //! Constructor
        RandomOrderedGenerationStrategy();

        //! Generates a random configuration
        /*!
        * \param size Configuration size
        * \param max Maximum value
        * \return A random ordered configuration (Solution)
        */
        Solution * generate(int size, int max);

    private:
        Randomizer rand;
        void place (int a, int b, int pos_1, int pos_2, vector<int> &config);
};
