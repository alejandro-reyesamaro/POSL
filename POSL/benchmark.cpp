#include "benchmark.h"

Benchmark::Benchmark()
{
}

void Benchmark::UpdateSolution(shared_ptr<Solution> sol)
{
    solution = sol;
}
