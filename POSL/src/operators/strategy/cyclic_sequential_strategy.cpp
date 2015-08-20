#include "cyclic_sequential_strategy.h"

#include <iostream>
using namespace std;

CyclicSequentialStrategy::CyclicSequentialStrategy(CompoundModule * _M1, BooleanExpression *_ex) : M1(_M1), ex(_ex)
{}

ComputationData * CyclicSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    //cout << "Inside CyclicOperator (strategy)" << endl;
    ComputationData * output = input;

    while(ex->evaluate(psp))
    {
        //cout << "Inside CyclicOperator (strategy) executing" << endl;
        output = M1->execute(psp, output);
        if(output == NULL) break;
    }
    return output;
}
