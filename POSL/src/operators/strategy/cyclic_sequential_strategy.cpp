#include "cyclic_sequential_strategy.h"

#include <iostream>
using namespace std;

CyclicSequentialStrategy::CyclicSequentialStrategy(CompoundModule * _M1, BooleanExpression *_ex)
    : M1(_M1), ex(_ex),
      output(nullptr)
{}

ComputationData * CyclicSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    output = input;
    while(ex->evaluate(psp))
    {
        output = M1->execute(psp, output);
        if(output == nullptr)
            break;
    }
    return output;
}
