#include "speed_parallel_strategy.h"
#include "../data/neighborhood.h"
#include "../data/union_neighborhood.h"
#include "../tools/chronometer.h"
#include "mpi.h"

#include <iostream>

#define TAG0 123
#define TAG1 234

SpeedParallelStrategy::SpeedParallelStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * SpeedParallelStrategy::evaluate(PSP *psp, ComputationData * input)
{
    int myid, numprocs;
    int tag;

    int * buff;
    * buff = 0;

    ComputationData * d;

    MPI_Init(&psp->ARGC, &psp->ARGV);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    if(myid == 0) {
        //cout << "proc. 0 " << endl;
        int source = myid; //int source = 0;
        int dest   = (myid + 1) % 2; //int dest = 1;
        int tag = (myid == 0)? TAG0 : TAG1;
        MPI_Request reqs[2];
        MPI_Status status[2];
        int * flag;

        MPI_Irecv(buff, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &reqs[0]);

        ComputationData * d1 = M1->execute(psp, input);

        MPI_Test(&reqs[0], flag, &status[0]);

        if(!flag) // Then, no data received
        {
            int to_sent = 1;
            MPI_Isend(&to_sent, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &reqs[1]);
            d = d1;
        }
    }
    MPI_Finalize();
    if(d != NULL) return d;
    exit(0);
}
