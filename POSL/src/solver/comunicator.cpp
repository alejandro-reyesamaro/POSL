#include "comunicator.h"
#include "mpi.h"

#include <iostream>
using namespace std;

Comunicator::Comunicator()
    : request(MPI_REQUEST_NULL),
      logging(false) // manually turned on/of to log behavior
{}

void Comunicator::sendMessage(vector<int> package, int procID)
{
    int tag = package[0];
    int pack_size = package.size();
    int * buffer = &package[0];    

    if (logging)
    {
        int id;
        MPI_Comm_rank(MPI_COMM_WORLD, &id);
        cout << "Sending information (" << pack_size << "INT of " << tag << ")  from " << id << " to " << procID << endl;
        logging = false;
    }

    MPI_Send(buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD);
}
