#include "scheduler.h"

#include <algorithm>

using namespace std;

Scheduler::Scheduler()
    : process_base(0), first_available_process(0)
{
}

int Scheduler::schedule(shared_ptr<POSL_Solver> solver)
{
    string solver_name = solver->solverName();
    vector<string>::iterator ptr_solver_name = find(solver_names.begin() + process_base, solver_names.end(), solver_name);
    int pos_to_return = 0;
    if(ptr_solver_name == solver_names.end())
    {
        solver_names.push_back(solver->solverName());
        pos_to_return = first_available_process ++;
    }
    else
        pos_to_return = ptr_solver_name - solver_names.begin();

    solver_instances->insert(solver_name, solver);
    return pos_to_return;
}

void Scheduler::connect(shared_ptr<POSL_Solver> solver, ConnectorInfo connector, int pID)
{
    string solver_name = solver->solverName();
    vector<string>::iterator ptr_solver_name = find(solver_names.begin() + process_base, solver_names.end(), solver_name);
    int solver_pos = ptr_solver_name - solver_names.begin();
    connections[solver_pos].push_back({ connector, pID});
}

shared_ptr<POSL_Solver> Scheduler::getSolverAt(int i)
{
    string solver_name = solver_names[i];
    shared_ptr<POSL_Solver> solver = solver_instances->mapOf(solver_name);

    pair<ConnectorInfo, int> p;
    ConnectorInfo ci;
    int pid;
    for(int j = 0; j < connections[i].size(); j++)
    {
        p = connections[i][j];
        ci = p.first;
        pid = p.second;
        solver->connect(ci, pid);
    }
    return solver;
}
