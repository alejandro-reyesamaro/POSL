#include "random_configuration_generation_strategy.h"

RandomConfigurationGenerationStrategy::RandomConfigurationGenerationStrategy(int configuration_size)
    : config(configuration_size)
{}

std::vector<int> RandomConfigurationGenerationStrategy::generate(shared_ptr<Randomizer> rand, std::shared_ptr<Domain> domain)
{
    int k = 0;
    int index = 0;
    for(int i = 0; i < config.size(); i++)
    {
        k = rand->NextInt(domain->minimum(i), domain->maximum(i));
        config[index++] = k;
    }
    return config;
}
