#include "random_configuration_generation_strategy.h"

#include <random>

RandomConfigurationGenerationStrategy::RandomConfigurationGenerationStrategy()
{
}

Solution * RandomConfigurationGenerationStrategy::generate(vector<Domain> domains, Seed * s)
{
    double seed = s->seed();
    default_random_engine generator (seed);

    vector<int> vec;

    for(vector<Domain>::iterator it = domains.begin(); it != domains.end(); ++it)
    {
        uniform_int_distribution<int> distribution(it->minimum(), it->maximum());
        int k = distribution(generator);
        vec.push_back(k);
    }

    Solution * new_solution = new Solution(domains, vec);    
    return new_solution;
}
