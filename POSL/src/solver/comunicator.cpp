#include "comunicator.h"
#include "mpi.h"

#include <iostream>
using namespace std;

Comunicator::Comunicator()
    : request(MPI_REQUEST_NULL)
{}

void Comunicator::sendMessage(Packable * data, int procID)
{
    vector<int> package = data->pack();
    int tag = package[0];
    int pack_size = package.size();
    int * buffer = &package[0];
    //MPI_Isend(&buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD, &request);
    MPI_Send(&buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD);
    cout << "Sending information (" << tag << ")  to " << procID << endl;
}
