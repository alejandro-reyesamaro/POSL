#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"
#include "computation/random_configuration_generation_strategy.h"

#include <random>
#include <limits>

#include <iostream>

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

ComputationData * OM_FlorianRandomConfGeneration::execute(PSP *psp, ComputationData * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy();
    return rconf->generate(psp->GetCurrentSolution()->domains, ((Seed *)input));


    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < 100; i++)
    {
        Solution * sol = rconf->generate(psp->GetCurrentSolution()->domains, new Seed());
        int cost = psp->GetBenchmark()->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = sol->configuration;
            best_cost = cost;
        }
    }
    Solution * new_solution = new Solution(psp->GetCurrentSolution()->domains, best_conf);
    psp->UpdateSolution(new_solution);
    return new_solution;
}
