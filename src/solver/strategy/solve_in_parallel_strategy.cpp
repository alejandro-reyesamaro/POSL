#include "solve_in_parallel_strategy.h"
#include "../../tools/tools.h"

#include <iostream>

#include "mpi.h"

using namespace std;

SolveInParallelStrategy::SolveInParallelStrategy(std::shared_ptr<Benchmark> bench, string _exe_path)
    : benchmark(bench),
      exe_path(_exe_path)
{}

string SolveInParallelStrategy::solve(shared_ptr<Scheduler> scheduler)//, shared_ptr<SearchProcessParamsStruct> psp_params)
{
    int myid = 0;
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    if(myid < scheduler->schedulerSize())
    {
        //cout << "sole_in_parallel_strategy.cpp PiD:" << myid << endl;
        shared_ptr<POSL_Solver> solver = scheduler->getSolverAt(myid);
        shared_ptr<SearchProcessParamsStruct> psp_params = solver->GetPspParams();
        psp_params->SetID(myid);
        psp_params->SetLogPath(exe_path);
        shared_ptr<PSP> psp(make_shared<PSP>(benchmark, psp_params));
        //cout << "sole_in_parallel_strategy.cpp PiD:" << myid << " (" << psp_params->GetTabuListSize() << ":" << psp_params->GetTabuEps() << ":" << psp_params->GetTabuNormType() << ")" << endl;
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
