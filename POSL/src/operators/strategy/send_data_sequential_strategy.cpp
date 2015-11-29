#include "send_data_sequential_strategy.h"

#include "mpi.h"

#include <iostream>

using namespace std;

SendDataSequentialStrategy::SendDataSequentialStrategy(shared_ptr<CompoundModule> _M1)
    : M1(_M1),
      output(nullptr)
{}

shared_ptr<ComputationData> SendDataSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    output = M1->execute(psp, input);
    psp->SendData(output->BuildPacker()->pack(), destinies);
    return output;
}

void SendDataSequentialStrategy::addDestiny(int pID)
{
    destinies.push_back(pID);
}
