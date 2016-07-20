#include "send_data_sequential_strategy.h"

#include "mpi.h"

#include <iostream>

using namespace std;

SendDataSequentialStrategy::SendDataSequentialStrategy(shared_ptr<CompoundModule> _M1)
    : M1(_M1),
      output(nullptr),
      comm(make_shared<Comunicator>()),
      log_first_delivery(false)  // manually turned on/of to log behavior
{}

shared_ptr<ComputationData> SendDataSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "SendDataSequentialStrategy::evaluate - sending data to " << destinies.size() << " destinies." << endl;
    output = M1->execute(psp, input);

    for(vector<int>::iterator it = destinies.begin(); it != destinies.end(); ++it)
    {
        comm->sendMessage(output->BuildPacker()->pack(), *it, log_first_delivery);
        //psp->log("Sending data");
        //cout << "sending data" << endl;
    }
    log_first_delivery = false;
    return output;
}

void SendDataSequentialStrategy::addDestiny(int pID)
{
    destinies.push_back(pID);
}
