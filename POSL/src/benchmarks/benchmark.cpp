#include "benchmark.h"

using namespace std;

Benchmark::Benchmark(vector<Domain> _domains, shared_ptr<SolutionCostStrategy> _cost_strategy)
    : domains(_domains),
      solution(make_shared<Solution>(_domains)),
      cost_strategy(_cost_strategy)
{}

int Benchmark::solutionCost(shared_ptr<Solution> sol){ return solutionCost(sol->GetConfiguration()); }

void Benchmark::UpdateSolution(shared_ptr<Solution> sol){ solution = sol; }
