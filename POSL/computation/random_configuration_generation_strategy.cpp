#include "random_configuration_generation_strategy.h"

RandomConfigurationGenerationStrategy::RandomConfigurationGenerationStrategy(Seed * s) : rand()
{}

Solution * RandomConfigurationGenerationStrategy::generate(vector<Domain> domains)
{
    vector<int> vec;

    for(vector<Domain>::iterator it = domains.begin(); it != domains.end(); ++it)
    {
        int k = rand.NextInt(it->minimum(), it->maximum());
        vec.push_back(k);
    }

    Solution * new_solution = new Solution(domains, vec);    
    return new_solution;
}
