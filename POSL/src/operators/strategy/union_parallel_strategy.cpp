#include "union_parallel_strategy.h"
#include "../../data/from_pack_neighborhood.h"
#include "../../data/union_neighborhood.h"
#include "mpi.h"

#include <iostream>
#include <thread>

#define TAG 123

UnionParallelStrategy::UnionParallelStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2),
      v1(nullptr),
      v2(nullptr)
{}

shared_ptr<ComputationData> UnionParallelStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    thread workerThread(&Executer::execute, &M2, psp, input);
    M1.execute(psp, input);
    v1 = static_pointer_cast<Neighborhood>(M1.GetOutput());
    workerThread.join();
    v2 = static_pointer_cast<Neighborhood>(M2.GetOutput());

    if (v1 == nullptr) return v2;
    if (v2 == nullptr) return v1;

    return make_shared<UnionNeighborhood>((Solution *)input, v1, v2);
}

/*
ComputationData * UnionParallelStrategy::evaluate(PSP *psp, ComputationData * input)
{
    boost::function<void(PSP*, ComputationData*)> func_M2 = boost::bind(&Executer::execute, &M2, _1, _2);
    boost::thread workerThread(func_M2, psp, input);
    M1.execute(psp, input);
    Neighborhood * v1 = (Neighborhood *)M1.GetOutput();
    workerThread.join();
    Neighborhood * v2 = (Neighborhood *)M2.GetOutput();
    Neighborhood * v = new UnionNeighborhood((Solution *)input, v1, v2);
    return v;
}

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

        if(myid == psp->ProcessA()) {
            //cout << "proc. 0 " << endl;
            Neighborhood * v1 = (Neighborhood *)M1->execute(psp, input);
            vector<int> vec_pack = v1->pack();
            pack_size = vec_pack.size();
            buff = &vec_pack[0]; //j=(int*)malloc(2*sizeof(int));
            ierr = MPI_Send(buff, pack_size, MPI_INT, 1, mytag, MPI_COMM_WORLD);
        }
        if(myid == psp->ProcessB()){
            //cout << "proc. 1 " << endl;
            Neighborhood * v2 = (Neighborhood *)M2->execute(psp, input);
            ierr = MPI_Probe(0,mytag,MPI_COMM_WORLD,&status);
            ierr = MPI_Get_count(&status,MPI_INT,&pack_size);
            buff = new int[pack_size];//(int*)malloc(pack_size*sizeof(int));
            ierr = MPI_Recv(buff, pack_size, MPI_INT, 0, mytag, MPI_COMM_WORLD, &status);
            Neighborhood * v1 = new FromPackNeighborhood(pack_size, buff);
            v = new UnionNeighborhood((Solution *)input, v1, v2);
        }
        if(myid == psp->ProcessB()) return v;
        //exit(0);
    }
    else
        throw "(POSL Exception) Not MPI initializing....";
}
*/
