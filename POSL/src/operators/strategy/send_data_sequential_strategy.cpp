#include "send_data_sequential_strategy.h"

#include "mpi.h"

#include <iostream>

using namespace std;

SendDataSequentialStrategy::SendDataSequentialStrategy(CompoundModule * _M1)
    : M1(_M1),
      output(nullptr)
{}

ComputationData * SendDataSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    output = M1->execute(psp, input);
    psp->SendData(output->BuildPacker()->pack());
    return output;
}
