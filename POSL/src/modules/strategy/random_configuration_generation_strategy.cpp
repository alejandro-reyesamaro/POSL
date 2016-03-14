#include "random_configuration_generation_strategy.h"

RandomConfigurationGenerationStrategy::RandomConfigurationGenerationStrategy(int configuration_size)
    : config(configuration_size)
{}

std::vector<int> RandomConfigurationGenerationStrategy::generate(shared_ptr<Randomizer> rand, std::vector<Domain> domains)
{
    int k = 0;
    int index = 0;
    for(std::vector<Domain>::iterator it = domains.begin(); it != domains.end(); ++it)
    {
        k = rand->NextInt(it->minimum(), it->maximum());
        config[index++] = k;
    }
    return config;
}
