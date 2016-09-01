#include "comunicator.h"
#include "mpi.h"

#include <iostream>
#include <ctime>

using namespace std;

Comunicator::Comunicator()
    : request(MPI_REQUEST_NULL)
{}

void Comunicator::sendMessage(std::vector<int> & package, int procID, bool logging)
{
    int tag = package[0];
    int pack_size = package.size();
    int * buffer = &package[0];

    //cout << pack_size << endl;

#ifdef MST // cpp.sh/5ms3g
    if(package_to_measure.size() != pack_size+1)
        package_to_measure.resize(pack_size+1);
    copy(package.begin(), package.end(), package_to_measure.begin());
    package_to_measure[pack_size] = clock();
    pack_size ++;
    buffer = &package_to_measure[0];
#endif

    if (logging)
    {
        int id;
        MPI_Comm_rank(MPI_COMM_WORLD, &id);
        cout << "Sending information (" << pack_size << "INT of " << tag << ")  from " << id << " to " << procID << endl;
        logging = false;
    }

    MPI_Send(buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD);
}
