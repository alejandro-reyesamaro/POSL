#include "cyclic_sequential_strategy.h"
#include <iostream>
#include "data/decision_pair.h"

CyclicSequentialStrategy::CyclicSequentialStrategy(CompoundModule * _M1, BooleanExpression *_ex) : M1(_M1), ex(_ex)
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
