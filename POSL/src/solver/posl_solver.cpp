#include "posl_solver.h"
#include "../tools/tools.h"
#include "strategy/show_bechmark_result_strategy.h"
#include "strategy/show_to_collect_strategy.h"

#include <iostream>
using namespace std;

POSL_Solver::POSL_Solver(string name, shared_ptr<Benchmark> _bench, shared_ptr<ComputationStrategy> _strategy)
    : solver_name(name),
      final_solution(nullptr),
      best_solution(nullptr),
      final_cost(-1),
      best_cost(-1),
      iterations(-1),
      time(-1),
      strategy(_strategy),
      bench(_bench),
      //showing_strategy(make_shared<ShowBechmarkResultStrategy>())
      showing_strategy(make_shared<ShowToCollectStrategy>())
{}

void POSL_Solver::solve(shared_ptr<PSP> psp)
{
    final_solution = strategy->execute(psp);
    final_cost = psp->GetBenchmark()->solutionCost(final_solution);
    best_solution = psp->GetBestSolutionSoFar();
    best_cost = psp->GetBenchmark()->solutionCost(best_solution);
    iterations = psp->GetIterations();
    time = psp->GetTime();
}

bool POSL_Solver::isOpen()
{
    vector<ConnectorInfo> j = Jacks();
    vector<ConnectorInfo> o = Outlets();
    return (j.size() != 0 || o.size());
}

string POSL_Solver::show(std::shared_ptr<PSP> psp)
{
    return showing_strategy->show(psp, bench, best_solution, best_cost, final_solution, final_cost, strategy->TAG, iterations, time);
}

vector<ConnectorInfo> POSL_Solver::Jacks()
{
    return strategy->GetCompoundModule()->Jacks();
}

vector<ConnectorInfo> POSL_Solver::Outlets()
{
    return strategy->GetCompoundModule()->Outlets();
}

void POSL_Solver::connect(ConnectorInfo connector, int procID)
{
    strategy->GetCompoundModule()->connect(connector, procID);
}
