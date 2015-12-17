#include "connection_operator_bipartition.h"

#include <iostream>

using namespace std;

ConnectionOperatorBipartition::ConnectionOperatorBipartition(vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_jacks,
                                                             vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_outlets)
    : solver_jacks(_solver_jacks),
      solver_outlets(_solver_outlets)
{}

void ConnectionOperatorBipartition::connect(shared_ptr<Scheduler> scheduler)
{
    shared_ptr<POSL_Solver> s_jack;
    ConnectorInfo jack;
    shared_ptr<POSL_Solver> s_outlet;
    ConnectorInfo outelt;
    int pid_solver_jack, pid_solver_outlet;
    for(unsigned int i = 0; i < solver_jacks.size(); i++)
    {
        s_jack = solver_jacks[i].first;
        jack = solver_jacks[i].second;
        s_outlet = solver_outlets[i].first;
        outelt = solver_outlets[i].second;

        pid_solver_jack = scheduler->schedule(s_jack);
        pid_solver_outlet = scheduler->schedule(s_outlet);
        if(pid_solver_outlet >= 0)
            scheduler->connect(s_jack, jack, pid_solver_outlet);
    }
}
