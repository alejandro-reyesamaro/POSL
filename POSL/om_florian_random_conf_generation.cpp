#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"

#include <random>
#include <limits>

#include <iostream>

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

ComputationData * OM_FlorianRandomConfGeneration::execute(Benchmark * bench, ComputationData * input)
{
    OperationModule * op = new OM_RandomConfGeneration();
    vector<Domain> domains = bench->solution->domains;


    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < 100; i++)
    {
        Solution * sol = (Solution *)(op->execute(bench, input));
        int cost = bench->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = sol->configuration;
            best_cost = cost;
        }
    }
    Solution * new_solution = new Solution(bench->solution->domains, best_conf);
    return new_solution;
}
