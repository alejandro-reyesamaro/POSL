#include "florian_sequential_strategy.h"

#ifndef N_ATTEMPTS
#define N_ATTEMPTS 100
#endif

#include <iostream>
#include <limits>

FlorianSequentialStrategy::FlorianSequentialStrategy(CompoundModule * _M1)
    : M1(_M1),
      temp_solution(nullptr),
      best_solution(nullptr)
{}

ComputationData * FlorianSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{    
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < N_ATTEMPTS; i++)
    {
        temp_solution = (Solution *)M1->execute(psp, input);
        int cost = psp->GetBenchmark()->solutionCost(temp_solution);
        if(cost < best_cost)
        {
            best_solution = temp_solution;
            best_cost = cost;
        }
    }

    psp->UpdateSolution(best_solution);
    return best_solution;
}
