#include "union_parallel_strategy.h"
#include "../data/neighborhood.h"
#include "../data/from_pack_neighborhood.h"
#include "../data/union_neighborhood.h"
#include "mpi.h"

#include <iostream>

#define TAG 123

UnionParallelStrategy::UnionParallelStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * UnionParallelStrategy::evaluate(PSP *psp, ComputationData * input)
{
    int myid, numprocs;
    MPI_Status status;
    int mytag,ierr,pack_size;

    int * buff;

    Neighborhood * v;

    int flag;
    MPI_Initialized(&flag);

    if(flag)
    {
        MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
        MPI_Comm_rank(MPI_COMM_WORLD,&myid);

        mytag=TAG;

        if(myid == 0) {
            //cout << "proc. 0 " << endl;
            Neighborhood * v1 = (Neighborhood *)M1->execute(psp, input);
            vector<int> vec_pack = v1->pack();
            pack_size = vec_pack.size();
            buff = &vec_pack[0]; //j=(int*)malloc(2*sizeof(int));
            ierr = MPI_Send(buff, pack_size, MPI_INT, 1, mytag, MPI_COMM_WORLD);
        }
        if(myid == 1){
            //cout << "proc. 1 " << endl;
            Neighborhood * v2 = (Neighborhood *)M2->execute(psp, input);
            ierr = MPI_Probe(0,mytag,MPI_COMM_WORLD,&status);
            ierr = MPI_Get_count(&status,MPI_INT,&pack_size);
            buff = new int[pack_size];//(int*)malloc(pack_size*sizeof(int));
            ierr = MPI_Recv(buff, pack_size, MPI_INT, 0, mytag, MPI_COMM_WORLD, &status);
            Neighborhood * v1 = new FromPackNeighborhood(pack_size, buff);
            v = new UnionNeighborhood((Solution *)input, v1, v2);
        }
        if(myid == 1) return v;
        exit(0);
    }
    else
        throw "Not MPI initializing....";
}
