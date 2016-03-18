#include "solve_in_parallel_strategy.h"
#include "../../tools/tools.h"

#include <iostream>

#include "mpi.h"

using namespace std;

SolveInParallelStrategy::SolveInParallelStrategy(std::shared_ptr<Benchmark> bench, string _exe_path)
    : benchmark(bench),
      exe_path(_exe_path)
{}

string SolveInParallelStrategy::solve(shared_ptr<Scheduler> scheduler)
{
    int myid = 0;
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    if(myid < scheduler->schedulerSize())
    {
        shared_ptr<POSL_Solver> solver = scheduler->getSolverAt(myid);
        shared_ptr<PSP> psp(make_shared<PSP>(benchmark, myid, exe_path));
        solver->solve(psp);
        string output = solver->show(psp);
        //string path = exe_path + "/POSLExRes_" + Tools::int2str(myid) + ".tmp";
        //outfile.open (path,  ios::out | ios::app);
        //outfile << output << endl;
        //outfile.close();
        return output;
    }
    else return Tools::int2str(myid) + "-POSL Meta-Solver: fail :/ (parallel)";
}
