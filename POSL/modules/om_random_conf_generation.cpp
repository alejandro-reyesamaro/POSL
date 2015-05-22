#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration()
{
}

ComputationData *OM_RandomConfGeneration::execute(Benchmark * bench, ComputationData * input)
{
    double seed = ((Seed *)input)->seed();
    default_random_engine generator (seed);

    vector<int> vec;

    for(vector<Domain>::iterator it = bench->solution->domains.begin(); it != bench->solution->domains.end(); ++it)
    {
        uniform_int_distribution<int> distribution(it->minimum(), it->maximum());
        int k = distribution(generator);
        vec.push_back(k);
    }

    Solution * new_solution = new Solution(bench->solution->domains, vec);
    return new_solution;
}
