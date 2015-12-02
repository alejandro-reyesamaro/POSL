#include "connection_operator_rin.h"

using namespace std;

ConnectionOperatorRin::ConnectionOperatorRin(vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_jacks,
                                                               vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_outlets)
    : solver_jacks(_solver_jacks),
      solver_outlets(_solver_outlets)
{}

void ConnectionOperatorRin::connect(shared_ptr<Scheduler> scheduler)
{
    shared_ptr<POSL_Solver> s_jack;
    ConnectorInfo jack;
    shared_ptr<POSL_Solver> s_outlet;
    ConnectorInfo outelt;
    int pid_solver_jack, pid_solver_outlet;
    int ss = solver_jacks.size();
    for(unsigned int i = 0; i < solver_jacks.size(); i++)
    {
        s_jack = solver_jacks[i].first;
        jack = solver_jacks[i].second;
        s_outlet = solver_outlets[(i + 1) % ss].first;
        outelt = solver_outlets[(i + 1) % ss].second;

        pid_solver_jack = scheduler->schedule(s_jack);
        pid_solver_outlet = scheduler->schedule(s_outlet);
        scheduler->connect(s_jack, jack, pid_solver_outlet);
    }
}
