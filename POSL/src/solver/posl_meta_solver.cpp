#include "posl_meta_solver.h"
#include "../solver/for_golfers_css.h"

#include <iostream>

using namespace std;

#include "mpi.h"

POSL_MetaSolver::POSL_MetaSolver()//vector<POSL_Solver *> _solvers)
    //: solvers(_solvers)
{
}

int mainProcess(int myid)
{
    return (myid % 2 == 0) ? myid : myid - 1;
}

int neighborProcess(int myid, int numprocs)
{
    if(myid % 2 == 0 && myid == numprocs - 1) return - 1;
    return (myid % 2 == 0) ? myid + 1 : myid;
}

void POSL_MetaSolver::solve(int argc, char **argv, Benchmark * bench)
{    
    int myid, numprocs;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    int procA = mainProcess(myid);
    int procB = neighborProcess(myid, numprocs);

    //cout << myid << " - " << numprocs << ": " << procA << "_" << procB << endl;

    FlagComputation * flagC = new FlagParallelComputation(procA, procB);
    PSP * psp = new PSP(argc, argv, bench, flagC);

    POSL_Solver * solver_1 = new POSL_Solver(psp, new ForGolfersCSS());
    POSL_Solver * solver_2 = new POSL_Solver(psp, new ForGolfersCSS());

    solvers.push_back(solver_1);
    solvers.push_back(solver_2);

    int numsolvers = solvers.size();
    int solver_index = (int(myid / 2)) % numsolvers;

    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);


    //cout << " DONE " << endl;

    //if(myid == 0)
    //{
        POSL_Solver * solver = solvers[solver_index];
        solver->solve();
        cout << solver->show() << endl;
    //}

    MPI_Finalize();
}
