#include "florian_sequential_strategy.h"

#ifndef N_ATTEMPTS
#define N_ATTEMPTS 100
#endif

using namespace std;

#include <iostream>
#include <limits>

FlorianSequentialStrategy::FlorianSequentialStrategy(int k, shared_ptr<CompoundModule> _M1)
    : M1(_M1),
      times(k),
      best_solution(nullptr),
      temp_solution(nullptr)
{}

shared_ptr<ComputationData> FlorianSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{    
    int best_cost = std::numeric_limits<int>::max();

    for(int i = 0; i < times; i++)
    {
        temp_solution = static_pointer_cast<Solution>(M1->execute(psp, input));
        int cost = psp->GetBenchmark()->solutionCost(temp_solution);
        if(cost < best_cost)
        {
            best_solution = temp_solution;
            best_cost = cost;
        }
    }
    //psp->UpdateSolution(best_solution);
    return best_solution;
}
