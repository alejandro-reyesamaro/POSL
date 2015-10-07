#include "comunicator.h"
//#include "../data/dStrategy/packable.h"
//#include "../data/decision_pair.h"
#include "mpi.h"

#include <iostream>
using namespace std;

Comunicator::Comunicator()
    : request(MPI_REQUEST_NULL)
{}

void Comunicator::sendMessage(vector<int> package, int procID)
{    
    int tag = package[0];
    int pack_size = package.size();
    int * buffer = &package[0];
    //MPI_Isend(&buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD, &request);
    //cout << "Sending information (" << tag << ")  to " << procID << endl; //<< ((DecisionPair *) data)->GetCurrent()->configurationToString()<< endl;
    MPI_Send(buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD);
    //cout << "Sending information (" << tag << ")  to " << procID << endl; //<< ((DecisionPair *) data)->GetCurrent()->configurationToString()<< endl;
    //delete[] buffer;
}
