#include "solve_sequentially_strategy.h"

#include <iostream>

using namespace std;

SolveSequentiallyStrategy::SolveSequentiallyStrategy(std::shared_ptr<Benchmark> bench)
    : benchmark(bench)
{}

string SolveSequentiallyStrategy::solve(shared_ptr<Scheduler> scheduler)//, shared_ptr<SearchProcessParamsStruct> psp_params)
{
    shared_ptr<POSL_Solver> solver = scheduler->getFirstSequentialSolver();
    if(solver)
    {
        shared_ptr<SearchProcessParamsStruct> psp_params = solver->GetPspParams();
        shared_ptr<PSP> psp(make_shared<PSP>(benchmark, psp_params));
        solver->solve(psp);
        return solver->show(psp);
    }
    else return "POSL Meta-Solver: fail :/ (sequential)";
}
