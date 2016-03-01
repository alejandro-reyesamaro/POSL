#include "data_open_channel.h"

#include <iostream>
using namespace std;

DataOpenChannel::DataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : OpenChannel(name),
      bench(_bench),
      logging(false), // manually turn it on/of to log behavior
      contains_information(false),
      buffer(2 + _bench->Domains().size() * 2)
{}

shared_ptr<ComputationData> DataOpenChannel::receive_and_log(int id, int tag, shared_ptr<PSP> psp)
{
    /*
    int pack_size;
    MPI_Get_count(&status, MPI_INT, &pack_size);

    //cout << "Receiving " << pack_size << " ints." << endl;
    int * buffer = new int[pack_size];
    MPI_Recv(buffer, pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
    //MPI_Irecv(buffer, pack_size, MPI_INT, MPI_ANY_SOURCE, dataTag(), MPI_COMM_WORLD, &request);
    //MPI_Test(&request, &test_flag, &status);

    cout << "Op.Ch: PID = "<< id <<". Receiving from " << status.MPI_SOURCE << endl;
    r = unpackMessage(buffer, psp);
    cout << "Op.Ch: PID = "<< id <<". Received " << r->Tag() << endl;
    delete[] buffer;
    logging = false;
    return r;
    */
}

shared_ptr<ComputationData> DataOpenChannel::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData>)
{
    //cout << "OPCh..." << endl;
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    int tag = dataID();
    int pack_size;
    int test_flag;

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);    
    while(test_flag)
    {
        if(logging)
            return receive_and_log(id, tag, psp);
        else
        {
            //psp->log("Receiving data");
            MPI_Get_count(&status, MPI_INT, &pack_size);
            //int * buffer = new int[pack_size];
            MPI_Recv(&buffer[0], pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
            received_data = storeMessage(&buffer[0], psp);
            contains_information = true;
            //delete[] buffer;
            //return r;
        }
        MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);        
    }
    //cout << "...OPCh" << endl;
    return selectMessage();
    //return nullptr;
}

shared_ptr<ComputationData> DataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        return received_data;
    }
    else return nullptr;
}
