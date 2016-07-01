#include "data_open_channel.h"

#include <iostream>
using namespace std;

DataOpenChannel::DataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : OpenChannel(name),
      contains_information(false),
      bench(_bench),
      received_data(nullptr),
      logging(false), // manually turn it on/of to log behavior
      buffer(2 + _bench->Dimension() * 2)
{}

void DataOpenChannel::receive_and_log(int id, int tag, shared_ptr<PSP> psp)
{
    int pack_size;
    //psp->log("Receiving data");
    MPI_Get_count(&status, MPI_INT, &pack_size);
    //int * buffer = new int[pack_size];
    cout << "Op.Ch: PID = " << id <<". Receiving " << pack_size << "INT from " << status.MPI_SOURCE << endl;
    MPI_Recv(&buffer[0], pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
    storeMessage(&buffer[0], psp);
    contains_information = true;
    cout << "Op.Ch: PID = "<< id <<". Received " << tag << endl;
    logging = false;
}

shared_ptr<ComputationData> DataOpenChannel::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData>)
{    
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    int tag = dataID();

    //cout << "OPCh... " << tag << endl;

    int pack_size;
    int test_flag;

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);    
    while(test_flag)
    {
        if(logging)
            receive_and_log(id, tag, psp);
        else
        {
            //psp->log("Receiving data");
            MPI_Get_count(&status, MPI_INT, &pack_size);
            //cout << "data_open_channel.cpp count = " << pack_size << endl;
            //int * buffer = new int[pack_size];
            MPI_Recv(&buffer[0], pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
            storeMessage(&buffer[0], psp);
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

