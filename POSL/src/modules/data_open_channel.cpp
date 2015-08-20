#include "data_open_channel.h"

DataOpenChannel::DataOpenChannel()
{}

ComputationData * DataOpenChannel::execute(PSP * psp, ComputationData * input)
{
    MPI_Status status;
    MPI_Request request;
    int pack_size;
    MPI_Probe(MPI_ANY_SOURCE, dataTag(), MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &pack_size);
    int * buffer = new int[pack_size];

    MPI_Irecv(buffer, pack_size, MPI_INT, MPI_ANY_SOURCE, dataTag(), MPI_COMM_WORLD, &request);

    int test_flag;
    MPI_Test(&request, &test_flag, &status);

    if(test_flag) // Then, no data received
    {
        return unpackMessage(buffer, psp);
    }
    else return NULL;
}

string DataOpenChannel::codeToSend()
{
    throw "(POSL Exception) Coded Open Channels is not allowed (DataOpenChannel.codeToSend)";
}
