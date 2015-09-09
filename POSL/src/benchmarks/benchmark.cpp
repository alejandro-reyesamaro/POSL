#include "benchmark.h"

Benchmark::Benchmark(std::vector<Domain> _domains)
    : domains(_domains),
      solution(std::make_shared<Solution>(_domains))
{}

int Benchmark::solutionCost(std::shared_ptr<Solution> sol){ return solutionCost(sol->GetConfiguration()); }

void Benchmark::UpdateSolution(std::shared_ptr<Solution> sol){ solution = sol; }
