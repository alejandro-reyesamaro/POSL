#include "binary_operator.h"
#include "../tools/tools.cpp"

using namespace std;

BinaryOperator::BinaryOperator(shared_ptr<CompoundModule> _M1,
                               shared_ptr<CompoundModule> _M2,
                               shared_ptr<SequentialExecutionStrategy> seq_strgy,
                               shared_ptr<ParallelExecutionStrategy> par_strgy)
    : Operator(seq_strgy, par_strgy), M1(_M1), M2(_M2)
{}

vector<ConnectorInfo> BinaryOperator::Jacks()
{
    return Tools::concat(M1->Jacks(), M2->Jacks());
}

vector<ConnectorInfo> BinaryOperator::Outlets()
{
    return Tools::concat(M1->Outlets(), M2->Outlets());
}

void BinaryOperator::connect(ConnectorInfo connector, int procID)
{
    M1->connect(connector, procID);
    M2->connect(connector, procID);
}
