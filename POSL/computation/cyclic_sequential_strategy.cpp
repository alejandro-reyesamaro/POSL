#include "cyclic_sequential_strategy.h"

CyclicSequentialStrategy::CyclicSequentialStrategy(CompoundModule * _M1, IteretionBoundExpression * _ex) : M1(_M1), ex(_ex)
{}

ComputationData * CyclicSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    ComputationData * output = input;

    while(ex->evaluate(psp))
    {
        output = M1->execute(psp, output);
    }
    return output;
}
