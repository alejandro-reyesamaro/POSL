#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"
#include "computation/random_configuration_generation_strategy.h"

#include <random>
#include <limits>

#include <iostream>

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

ComputationData * OM_FlorianRandomConfGeneration::execute(Benchmark * bench, ComputationData * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy();
    return rconf->generate(bench->GetSolution()->domains, ((Seed *)input));


    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < 100; i++)
    {
        Solution * sol = rconf->generate(bench->GetSolution()->domains, ((Seed *)input));
        int cost = bench->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = sol->configuration;
            best_cost = cost;
        }
    }
    Solution * new_solution = new Solution(bench->GetSolution()->domains, best_conf);
    bench->UpdateSolution(new_solution);
    return new_solution;
}
