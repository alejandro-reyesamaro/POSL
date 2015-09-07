#include "benchmark.h"

Benchmark::Benchmark(vector<Domain> _domains)
    : domains(_domains)
{}

int Benchmark::solutionCost(shared_ptr<Solution> sol){ return solutionCost(sol->GetConfiguration()); }

void Benchmark::UpdateSolution(shared_ptr<Solution> sol){ solution = sol; }
