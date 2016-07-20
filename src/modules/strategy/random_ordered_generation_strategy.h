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

//#include <random>

/*!
 * \class RandomOrderedGenerationStrategy random_ordered_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but ordered
 */
class RandomOrderedGenerationStrategy
{
    public:
        RandomOrderedGenerationStrategy(int configuration_size);

        std::vector<int> generate(shared_ptr<Randomizer> rand, int max);

    private:        
        void place (shared_ptr<Randomizer> rand, int a, int b, int pos_1, int pos_2);

        std::vector<int> config;
};
