#include "speed_parallel_strategy.h"
#include "../../tools/chronometer.h"
#include "mpi.h"

#include <iostream>
#include <thread>
//#include <boost/thread/thread.hpp>

#define TAG0 123
#define TAG1 234

SpeedParallelStrategy::SpeedParallelStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2)
{}

shared_ptr<ComputationData> SpeedParallelStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    // FALTA ESTOOOOOOOO
    thread workerThread(&Executer::execute, &M2, psp, input);
    M1.execute(psp, input);
    shared_ptr<ComputationData> r1 = M1.GetOutput();
    workerThread.join();
    shared_ptr<ComputationData> r2 = M2.GetOutput();
    return r2;
}

/*
ComputationData * SpeedParallelStrategy::evaluate(PSP *psp, ComputationData * input)
{
    int myid, numprocs;
    int tag;

    int * buff = new int[1];
    buff[0] = 0;

    MPI_Request reqs[2];
    MPI_Status status[2];

    //cout << "speed strategy" << endl;

    ComputationData * d;
    d = NULL;

    int flag;
    MPI_Initialized(&flag);

    if(flag)
    {
        MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
        MPI_Comm_rank(MPI_COMM_WORLD,&myid);

        if( myid == psp->ProcessA() || myid == psp->ProcessB() )
        {
            cout << "proc: " << myid << endl;

            int source = myid; //int source = 0;
            int dest   = (myid == psp->ProcessA()) //(myid + 1) % 2; //int dest = 1;
                    ? psp->ProcessB()
                    : psp->ProcessA();
            tag = (myid == psp->ProcessA())? TAG0 : TAG1;

            MPI_Irecv(buff, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &reqs[0]);

            ComputationData * d1 = M1->execute(psp, input);

            int test_flag;
            MPI_Test(&reqs[0], &test_flag, &status[0]);

            if(!test_flag) // Then, no data received
            {
                int to_sent = 1;
                MPI_Isend(&to_sent, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &reqs[1]);
                d = d1;
            }
        }
        if(d != NULL) return d;
        //exit(0);

    }
    else
        throw "(POSL Exception) Not MPI initializing....";
}
 */
