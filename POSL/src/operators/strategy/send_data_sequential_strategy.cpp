#include "send_data_sequential_strategy.h"

#include "mpi.h"

#include <iostream>

using namespace std;

SendDataSequentialStrategy::SendDataSequentialStrategy(shared_ptr<CompoundModule> _M1)
    : M1(_M1),
      output(nullptr),
      comm(make_shared<Comunicator>())
{}

shared_ptr<ComputationData> SendDataSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "sending data" << endl;
    output = M1->execute(psp, input);
    for(vector<int>::iterator it = destinies.begin(); it != destinies.end(); ++it)
    {
        comm->sendMessage(output->BuildPacker()->pack(), *it);
        //psp->log("Sending data");
        //cout << "sending data" << endl;
    }
    return output;
}

void SendDataSequentialStrategy::addDestiny(int pID)
{
    destinies.push_back(pID);
}
