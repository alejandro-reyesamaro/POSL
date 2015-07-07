#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"
#include "computation/random_configuration_generation_strategy.h"

#include <random>
#include <limits>
#include <iostream>

#define N_ATTEMPTS 100

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

ComputationData * OM_FlorianRandomConfGeneration::execute(PSP *psp, ComputationData * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy((Seed *)input);
    return rconf->generate(psp->GetCurrentSolution()->domains);


    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < N_ATTEMPTS; i++)
    {
        Solution * sol = rconf->generate(psp->GetCurrentSolution()->domains);
        int cost = psp->GetBenchmark()->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = sol->configuration;
            best_cost = cost;
        }
    }
    Solution * new_solution = new Solution(psp->GetCurrentSolution()->domains, best_conf);
    psp->UpdateSolution(new_solution);
    psp->UpdateBestSolution(new_solution);
    return new_solution;
}
