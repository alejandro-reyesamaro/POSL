#include "om_florian_random_conf_generation.h"
#include "om_random_conf_generation.h"
#include "strategy/random_configuration_generation_strategy.h"

#include <random>
#include <limits>
#include <iostream>

#define N_ATTEMPTS 100

OM_FlorianRandomConfGeneration::OM_FlorianRandomConfGeneration()
{
}

Solution * OM_FlorianRandomConfGeneration::spcf_execute(PSP *psp, Solution * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy();

    vector<int> best_conf;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < N_ATTEMPTS; i++)
    {
        Solution * sol = rconf->generate(psp->GetBenchmark()->Domains());
        int cost = psp->GetBenchmark()->solutionCost(sol);
        if(cost < best_cost)
        {
            best_conf = sol->GetConfiguration();
            best_cost = cost;
        }
    }
    Solution * new_solution = new Solution(psp->GetBenchmark()->Domains(), best_conf);
    psp->UpdateSolution(new_solution);
    return new_solution;
}

string OM_FlorianRandomConfGeneration::codeToSend()
{
    return "A3";
}
