#pragma once

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../data/seed.h"
#include "../../tools/randomizer.h"

//#include <random>

/*!
 * \class RandomConfigurationGenerationStrategy random_configuration_generation_strategy.h
 * \brief Class to generate random configurations (Solutions)
 */
class FarRandomConfigurationGenerationStrategy
{
    public:
        FarRandomConfigurationGenerationStrategy(int configuration_size, vector<int> _domain);

        std::vector<int> generate(shared_ptr<Randomizer> rand,
                                  std::vector<std::vector<int>> & existing_confs,
                                  int min_percentage_of_changes);

    private:
        std::vector<int> config;
        vector<int> domain;
        std::vector<int> variables_indexes;
};
