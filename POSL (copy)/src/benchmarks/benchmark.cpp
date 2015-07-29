#include "benchmark.h"

Benchmark::Benchmark()
{
}

void Benchmark::UpdateSolution(Solution * sol)
{
    solution = sol;
}

Solution * Benchmark::GetSolution()
{
    return solution;
}
