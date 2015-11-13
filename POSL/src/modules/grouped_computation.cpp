#include "grouped_computation.h"

using namespace std;

GroupedComputation::GroupedComputation(std::shared_ptr<Operator> _op)
    : op(_op)
{}

shared_ptr<HashMap<string, string>> GroupedComputation::GetConnections()
{
    return op->GetConnections();
}

void GroupedComputation::UpdateConnections(shared_ptr<HashMap<string, string>> connections_table)
{
    op->UpdateConnections(connections_table);
}
