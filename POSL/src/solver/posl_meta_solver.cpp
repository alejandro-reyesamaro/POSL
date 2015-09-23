#include "posl_meta_solver.h"
#include "../solver/for_golfers_css.h"

#include <iostream>

using namespace std;

#include "mpi.h"

#define TAG 1001

POSL_MetaSolver::POSL_MetaSolver(vector<shared_ptr<POSL_Solver> > _solvers)
    : solvers(_solvers)
{}

/*
int mainProcess(int myid)
{
    return (myid % 2 == 0) ? myid : myid - 1;
}

int neighborProcess(int myid, int numprocs)
{
    if(myid % 2 == 0 && myid == numprocs - 1) return - 1;
    return (myid % 2 == 0) ? myid + 1 : myid;
}
*/

void POSL_MetaSolver::solve(int argc, char **argv, shared_ptr<Benchmark> bench)
{    
    solve_Default(argc, argv, bench);
}

void POSL_MetaSolver::solve_Default(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));
    if(myid == 0)
    {
        psp->connectWith(1);
        psp->connectWith(3);
    }

    int numsolvers = solvers.size();
    int solver_index = myid % numsolvers;

    //cout << myid << " - solver: " << solver_index << endl;

    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}

/*
void POSL_MetaSolver::solve_MS(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size, numprocs, tag;
    int * buff = new int[1];
    MPI_Request reqs[2];
    MPI_Status status[2];

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    numprocs = comm_size - 1;    

    //cout << myid << " - " << numprocs << ": " << procA << "_" << procB << endl;

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench));

    int numsolvers = solvers.size();
    int solver_index = (int(myid / 2)) % numsolvers;

    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);

    int master_proc =  numprocs;
    tag = TAG;

    if(myid != numprocs) // SLAVE
    {
        shared_ptr<POSL_Solver> solver = solvers[solver_index];
        solver->solve(psp);
        cout << solver->show(psp->GetBenchmark()) << endl;

        int to_send = 1;
        MPI_Isend(&to_send, 1, MPI_INT, master_proc, tag, MPI_COMM_WORLD, &reqs[1]);
    }
    else // MASTER
    {
        MPI_Recv(buff, 1, MPI_INT, MPI_ANY_SOURCE, TAG, MPI_COMM_WORLD, &status[0]);
        cout << "(Y)" << endl;
        exit(0);
    }

    MPI_Finalize();
}
*/
