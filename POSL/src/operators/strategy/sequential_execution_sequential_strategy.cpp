#include "sequential_execution_sequential_strategy.h"

#include <iostream>
using namespace std;

SequentialExecutionSequentialStrategy::SequentialExecutionSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2)
{}

shared_ptr<ComputationData> SequentialExecutionSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    /*
    shared_ptr<ComputationData> aux = M1->execute(psp, input);
    if(!aux)
    {
        cout << "sequential_execution_sequential_strategy.cpp " << endl;
        cout << M1->Tag() << endl;
        cout << M2->Tag() << endl;
    }
    */
    return M2->execute(psp, M1->execute(psp, input));
}
