#include "cyclic_sequential_strategy.h"

#include <iostream>
using namespace std;

CyclicSequentialStrategy::CyclicSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<BooleanExpression> _ex)
    : M1(_M1), ex(_ex),
      output(nullptr)
{}

shared_ptr<ComputationData> CyclicSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << psp->GetPID() << ": cyc" << endl;
    output = input;
    while(ex->evaluate(psp))
    {
        output = M1->execute(psp, output);
        if(output == nullptr)
            break;
    }
    return output;
}
