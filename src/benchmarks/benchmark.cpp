#include "benchmark.h"
#include "../tools/tools.h"
#include <algorithm>

using namespace std;

Benchmark::Benchmark(int _dimension,
                     shared_ptr<Domain> _domain,
                     shared_ptr<SolutionCostStrategy> _cost_strategy,
                     shared_ptr<RelativeCostStrategy> _relative_cost_strategy,
                     shared_ptr<ShowStrategy> _show_strategy)
    : problem_dimension(_dimension),
      domain(_domain),
      configuration(_dimension, 0),
      default_configuration(_dimension, 0),
      cost_strategy(_cost_strategy),
      relative_cost_strategy(_relative_cost_strategy),
      show_strategy(_show_strategy)
{}

int Benchmark::solutionCost(shared_ptr<Solution> sol)
{
    return solutionCost(sol->get_conf_by_ref());
}
int Benchmark::relativeSolutionCost(std::vector<int> & configuration)
{
    return relative_cost_strategy->relativeSolutionCost(configuration);
}
int Benchmark::relativeSolutionCost(std::vector<int> & new_config, T_Changes changes)
{
    return relative_cost_strategy->relativeSolutionCost(new_config, changes);
}

int Benchmark::solutionCost(std::vector<int> & configuration)
{
    return cost_strategy->solutionCost(configuration);
}

int Benchmark::currentCost()
{
    return relative_cost_strategy->currentCost();
}

int Benchmark::costOnVariable(int index)
{
    return relative_cost_strategy->costOnVariable(index);
}

int Benchmark::sickestVariable()
{
    return relative_cost_strategy->sickestVariable();
}

void Benchmark::UpdateSolution(std::vector<int> & config)
{    
    relative_cost_strategy->updateConfiguration(config);
    copy(config.begin(), config.end(), configuration.begin());
}

void Benchmark::InitializeCostData(std::vector<int> & config)
{
    relative_cost_strategy->initializeCostData(config, solutionCost(config));
    copy(config.begin(), config.end(), configuration.begin());
}

string Benchmark::ShowSolution(shared_ptr<Solution> solution)
{
    return show_strategy->showSolution(solution);
}

shared_ptr<Solution> Benchmark::GetSolution()
{
    return make_shared<Solution>(domain, configuration);
}

vector<int> Benchmark::Reset()
{
    return configuration;
}

void Benchmark::SetDefaultConfiguration(std::vector<int> & _default_configuration)
{
    copy(_default_configuration.begin(), _default_configuration.end(), default_configuration.begin());
}
vector<int> Benchmark::GetDefaultConfiguration()
{
    return default_configuration;
}
