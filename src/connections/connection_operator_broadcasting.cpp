#include "connection_operator_broadcasting.h"

using namespace std;

ConnectionOperatorBroadcasting::ConnectionOperatorBroadcasting(vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_jacks,
                                                               vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solver_outlets)
    : solver_jacks(_solver_jacks),
      solver_outlets(_solver_outlets)
{}

void ConnectionOperatorBroadcasting::connect(shared_ptr<Scheduler> scheduler)
{
    shared_ptr<POSL_Solver> s_jack;
    ConnectorInfo jack;
    shared_ptr<POSL_Solver> s_outlet;
    ConnectorInfo outelt;
    //int pid_solver_jack;
    int pid_solver_outlet;
    for(unsigned int i = 0; i < solver_jacks.size(); i++)
    {
        s_jack = solver_jacks[i].first;
        jack = solver_jacks[i].second;
        for(unsigned int j = 0; j < solver_outlets.size(); j++)
        {
            s_outlet = solver_outlets[j].first;
            outelt = solver_outlets[j].second;
            // If jack and outlet are compatibles
            /*pid_solver_jack = */ scheduler->schedule(s_jack);
            pid_solver_outlet = scheduler->schedule(s_outlet);
            scheduler->connect(s_jack, jack, pid_solver_outlet);
        }
    }
}
