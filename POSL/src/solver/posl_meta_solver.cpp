#include "posl_meta_solver.h"
#include "../solver/for_golfers_css.h"
#include <math.h>
#include "../tools/hash_map.h"
#include "../tools/coding_tools.h"
#include "../packing/posl_uncoder.h"
#include "../packing/connections_declaration.h"

#include <iostream>

using namespace std;

#include "mpi.h"

#define TAG 1001

POSL_MetaSolver::POSL_MetaSolver(vector<shared_ptr<POSL_Solver> > _solvers)
    : solvers(_solvers)
{}


POSL_MetaSolver::POSL_MetaSolver(string code, int _comm_size, shared_ptr<Benchmark> bench)
    : comm_size(_comm_size)
{
    shared_ptr<PoslUncoder> posl_unc;
    pair<string, string> codes = CodingTools::splitDeclarationConnectionsFromFile("PATH");
    HashMap<string, shared_ptr<POSL_Solver>> solver_list = posl_unc->uncode_declarations(codes.first, bench);
    //vector<ConnectionsDeclaration> connections = posl_unc->
}


void POSL_MetaSolver::solve(int argc, char **argv, std::shared_ptr<Benchmark> bench)
{

}


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

void POSL_MetaSolver::solve(int argc, char **argv, shared_ptr<Benchmark> bench, unsigned int opt)
{
    if(opt == 0)
        solve_Default_NO(argc, argv, bench);
    else if (opt > 0 && opt < 100)
    {
        //int factor = 200/opt;
        //cout << factor << endl;
        solve_Default_50(argc, argv, bench, round(200/opt));
    }
    else if (opt >= 100)
        solve_Default_All(argc, argv, bench);
}

void POSL_MetaSolver::solve_Default_NO(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index = 2;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}

void POSL_MetaSolver::solve_Default_50(int argc, char **argv, shared_ptr<Benchmark> bench, int factor)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index;
    factor = min(factor, comm_size);
    //if(myid == 0)
    //    cout << "Factor: " << factor << endl;

    //*********************************************
    //        50 % Communication
    //*********************************************
    if(myid < comm_size/factor)
    {
        //psp->connectWith(comm_size/factor + myid);
        solver_index = 0;
        //cout << "Core " << myid << " conected with core " << comm_size/4 + myid << endl;
    }
    else if((myid >= comm_size/factor) && myid < comm_size/(factor/2))
        solver_index = 1;
    else
        solver_index = 2;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}

void POSL_MetaSolver::solve_Default_All(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index;

    //*********************************************
    //        All Communication
    //*********************************************
    if(myid < comm_size/2)
    {
        //psp->connectWith(comm_size/2 + myid);
        solver_index = 0;
        //cout << "Core " << myid << " conected with core " << comm_size/2 + myid << endl;
    }
    else
        solver_index = 1;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}
