#include "rho_operator.h"
#include "strategy/not_implemented_parallel_strategy.h"
#include "strategy/rho_sequential_strategy.h"
#include "../tools/tools.h"

using namespace std;

RhoOperator::RhoOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, float _rho)
    : BinaryOperator(_M1, _M2, make_shared<RhoSequentialStrategy>(_M1, _M2, _rho), make_shared<NotImplementedParallelStrategy>()),
      rho(_rho)
{}

string RhoOperator::codeToSend()
{
    return "3 (" + Tools::float2str(rho) + ") " + M1->codeToSend() + " " + M2->codeToSend();
}
