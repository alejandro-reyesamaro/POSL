#include "data_open_channel.h"

#include <iostream>
using namespace std;

DataOpenChannel::DataOpenChannel(shared_ptr<Benchmark> _bench)
    : bench(_bench)
{}

shared_ptr<ComputationData> DataOpenChannel::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    int tag = dataTag();
    //cout << "Op.Ch. (" << tag << ") of " << id << endl;
    MPI_Status status;
    //MPI_Request request;
    int pack_size;
    int test_flag;

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    if(test_flag)
    {
        MPI_Get_count(&status, MPI_INT, &pack_size);
        //cout << "Receiving " << pack_size << " ints" << endl;
        int * buffer = new int[pack_size];
        MPI_Recv(buffer, pack_size, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        //MPI_Irecv(buffer, pack_size, MPI_INT, MPI_ANY_SOURCE, dataTag(), MPI_COMM_WORLD, &request);
        //MPI_Test(&request, &test_flag, &status);

        //cout << "PID = "<< id <<". Receiving from " << status.MPI_SOURCE << endl;
        shared_ptr<ComputationData> r = unpackMessage(buffer, psp);
        //cout << "PID = "<< id <<". Receiving " << r->Tag() << endl;
        delete[] buffer;
        return r;
        //return unpackMessage(buffer, psp);
    }
    else return nullptr;
}

string DataOpenChannel::codeToSend()
{
    throw "(POSL Exception) Coded Open Channels is not allowed (DataOpenChannel.codeToSend)";
}
