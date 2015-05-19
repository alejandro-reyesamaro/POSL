#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"

#include <random>
#include <chrono>
#include <limits>

#include <iostream>

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

vector<int> OM_FlorianRandomConfGeneration::execute(shared_ptr<Benchmark> input)
{
    shared_ptr<OperationModule<shared_ptr<Benchmark>, vector<int>>> op = make_shared<OM_RandomConfGeneration>();
    vector<Domain> domains = input->solution->domains;


    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < 100; i++)
    {
        vector<int> rand_conf = op->execute(input);
        shared_ptr<Solution> sol = make_shared<Solution>(domains, rand_conf);
        int cost = input->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = rand_conf;
            best_cost = cost;
        }
    }
    return best_conf;
}
