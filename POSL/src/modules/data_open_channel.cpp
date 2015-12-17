#include "data_open_channel.h"

#include <iostream>
using namespace std;

DataOpenChannel::DataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : OpenChannel(name),
      bench(_bench),
      logging(false) // manually turned on/of to log behavior
{}

shared_ptr<ComputationData> DataOpenChannel::receive_and_log(int id, int tag, shared_ptr<PSP> psp)
{
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
}

shared_ptr<ComputationData> DataOpenChannel::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData>)
{
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    int tag = dataID();
    int pack_size;
    int test_flag;

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    if(test_flag)
    {
        if(logging)
            return receive_and_log(id, tag, psp);
        else
        {
            MPI_Get_count(&status, MPI_INT, &pack_size);
            int * buffer = new int[pack_size];
            MPI_Recv(buffer, pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
            r = unpackMessage(buffer, psp);
            delete[] buffer;
            return r;
        }
    }
    else return nullptr;
}


/*
string DataOpenChannel::codeToSend()
{
    throw "(POSL Exception) Coded Open Channels is not allowed (DataOpenChannel.codeToSend)";
}
*/
