#include "far_random_configuration_generation_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>

FarRandomConfigurationGenerationStrategy::FarRandomConfigurationGenerationStrategy(int configuration_size, vector<int> _domain)
    : config(configuration_size),
      domain(_domain),
      variables_indexes(Tools::generateMonotony(configuration_size))
{
}

vector<int> FarRandomConfigurationGenerationStrategy::generate(shared_ptr<Randomizer> rand,
                                                               vector<std::vector<int>> & existing_confs,
                                                               int min_percentage_of_changes)
{
    vector<vector<int>> values_per_variable(config.size(), vector<int>(0));
    // collecting the existing values for each variable
    for(unsigned int i = 0; i < existing_confs.size(); i++)
        for(unsigned int j = 0; j < config.size(); j ++)
            values_per_variable[j].push_back(existing_confs[i][j]);
    // sorting the existing values
    for(unsigned int i = 0; i < values_per_variable.size(); i++)
        sort(values_per_variable[i].begin(), values_per_variable[i].end());

    int variables_to_change = rand->NextInt(min_percentage_of_changes, 100) * config.size() / 100;
    rand->vector_shuffle(variables_indexes);

    // FAR values
    for(int i = 0; i < variables_to_change; i ++)
    {
        vector<int> posible_values(domain.size());
        copy(domain.begin(), domain.end(), posible_values.begin());
        for(unsigned int existing_value_j = 0; existing_value_j < values_per_variable[variables_indexes[i]].size(); existing_value_j ++)
        {
            posible_values.erase(remove(posible_values.begin(),
                                        posible_values.end(),
                                        values_per_variable[variables_indexes[i]][existing_value_j]),
                                 posible_values.end());
        }
        config[variables_indexes[i]] = (posible_values.size() > 0)
                                     ? rand->NextInt(0, posible_values.size())
                                     : domain[rand->NextInt(0, domain.size())];
    }

    // Irrelevant values
    for(int i = variables_to_change; i < (int)config.size(); i ++)
        config[variables_indexes[i]] = domain[rand->NextInt(0, domain.size())];
    return config;
}
