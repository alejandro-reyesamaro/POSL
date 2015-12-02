#include "connection_operator_no_connection.h"

using namespace std;

ConnectionOperatorNoConnection::ConnectionOperatorNoConnection(vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> _solvers)
    : solvers(_solvers)
{}

void ConnectionOperatorNoConnection::connect(shared_ptr<Scheduler> scheduler)
{
    shared_ptr<POSL_Solver> s;
    int pid;

    for(unsigned int i = 0; i < solvers.size(); i++)
    {
        s = solvers[i].first;
        pid = scheduler->schedule(s);
    }
}
