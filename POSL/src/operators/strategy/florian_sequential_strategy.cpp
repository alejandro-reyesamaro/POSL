#include "florian_sequential_strategy.h"

#ifndef N_ATTEMPTS
#define N_ATTEMPTS 100
#endif

#include <iostream>
#include <limits>

FlorianSequentialStrategy::FlorianSequentialStrategy(CompoundModule * _M1) : M1(_M1)
{}

ComputationData * FlorianSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    Solution * best;
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < N_ATTEMPTS; i++)
    {
        Solution * sol = (Solution *)M1->execute(psp, input);
        int cost = psp->GetBenchmark()->solutionCost(sol);
        if(cost < best_cost)
        {
            best = sol;
            best_cost = cost;
        }
    }

    psp->UpdateSolution(best);
    return best;
}
