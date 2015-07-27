#include "rho_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"
#include "../computation/rho_sequential_strategy.h"
#include "../tools/tools.h"

RhoOperator::RhoOperator(CompoundModule *_M1, CompoundModule *_M2, float _rho)
    : BinaryOperator(_M1, _M2, new RhoSequentialStrategy(_M1, _M2, _rho), new NotImplementedParallelStrategy()),
      rho(_rho)
{}

string RhoOperator::codeToSend()
{
    return "3 (" + Tools::float2str(rho) + ") " + M1->codeToSend() + " " + M2->codeToSend();
}
