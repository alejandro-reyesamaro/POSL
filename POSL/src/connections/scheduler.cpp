#include "scheduler.h"

#include <algorithm>

using namespace std;

Scheduler::Scheduler(int _capacity)
    : process_base(0),
      first_available_process(0),
      capacity(_capacity),
      solver_instances(make_shared<HashMap<std::string, std::shared_ptr<POSL_Solver>>>())
{}

void Scheduler:: checkOut()
{
    process_base = first_available_process;
}

int Scheduler::schedule(shared_ptr<POSL_Solver> solver)
{
    // Scheduler capacity overflows (capacity == # of cores)
    if(first_available_process == capacity)
        return -1;
    string solver_name = solver->solverName();
    vector<string>::iterator ptr_solver_name = find(solver_names.begin() + process_base, solver_names.end(), solver_name);
    int pos_to_return = 0;
    if(ptr_solver_name == solver_names.end())
    {
        solver_names.push_back(solver->solverName());
        connections.push_back(vector<pair<ConnectorInfo, int>>()); // the vector connections to the solver
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
    if(ptr_solver_name != solver_names.end())
    {
        int solver_pos = ptr_solver_name - solver_names.begin();
        connections[solver_pos].push_back({ connector, pID});
    }
}

shared_ptr<POSL_Solver> Scheduler::getSolverAt(int i)
{
    string solver_name = solver_names[i];
    shared_ptr<POSL_Solver> solver = solver_instances->mapOf(solver_name);

    pair<ConnectorInfo, int> p;
    ConnectorInfo ci;
    int pid;
    for(unsigned int j = 0; j < connections[i].size(); j++)
    {
        p = connections[i][j];
        ci = p.first;
        pid = p.second;
        solver->connect(ci, pid);
    }
    return solver;
}

shared_ptr<POSL_Solver> Scheduler::getFirstSequentialSolver()
{
    shared_ptr<POSL_Solver> solver;
    for ( auto it = solver_instances->it_begin(); it != solver_instances->it_end(); ++it )
        if(!it->second->isOpen())
        {
            solver = it->second;
            break;
        }
    return solver;
}
