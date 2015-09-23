#include "benchmark.h"

#include <algorithm>

using namespace std;

Benchmark::Benchmark(vector<Domain> _domains, shared_ptr<SolutionCostStrategy> _cost_strategy)
    : domains(_domains),
      configuration(_domains.size(),0),
      cost_strategy(_cost_strategy)
{}

int Benchmark::solutionCost(shared_ptr<Solution> sol){ return solutionCost(sol->GetConfiguration()); }

void Benchmark::UpdateSolution(vector<int> config)
{
    copy(config.begin(), config.end(), configuration.begin());
}

shared_ptr<Solution> Benchmark::GetSolution()
{
    return make_shared<Solution>(domains, configuration);
}
