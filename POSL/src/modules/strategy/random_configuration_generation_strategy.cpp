#include "random_configuration_generation_strategy.h"

RandomConfigurationGenerationStrategy::RandomConfigurationGenerationStrategy(int configuration_size)
    : rand(),
      config(configuration_size)
{}

vector<int> RandomConfigurationGenerationStrategy::generate(vector<Domain> domains)
{
    int k = 0;
    int index = 0;
    for(vector<Domain>::iterator it = domains.begin(); it != domains.end(); ++it)
    {
        k = rand.NextInt(it->minimum(), it->maximum());
        config[index++] = k;
    }
    return config;
}
