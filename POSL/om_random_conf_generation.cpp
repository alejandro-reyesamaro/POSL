#include "om_random_conf_generation.h"

#include <random>
#include <chrono>

#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration()
{
}

vector<int> OM_RandomConfGeneration::execute(shared_ptr<Benchmark> input)
{
    double seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    vector<int> vec;

    for(vector<Domain>::iterator it = input->solution->domains.begin(); it != input->solution->domains.end(); ++it)
    {
        uniform_int_distribution<int> distribution(it->minimum(), it->maximum());
        int k = distribution(generator);
        vec.push_back(k);
    }
    return vec;
}
