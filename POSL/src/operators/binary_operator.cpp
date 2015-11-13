#include "binary_operator.h"

using namespace std;

BinaryOperator::BinaryOperator(shared_ptr<CompoundModule> _M1,
                               shared_ptr<CompoundModule> _M2,
                               shared_ptr<SequentialExecutionStrategy> seq_strgy,
                               shared_ptr<ParallelExecutionStrategy> par_strgy)
    : Operator(seq_strgy, par_strgy), M1(_M1), M2(_M2)
{}

shared_ptr<HashMap<string, string>> BinaryOperator::GetConnections()
{
    return M1->GetConnections()->merge(M2->GetConnections());
}

void BinaryOperator::UpdateConnections(shared_ptr<HashMap<string, string>> connections_table)
{
    M1->UpdateConnections(connections_table);
    M2->UpdateConnections(connections_table);
}
