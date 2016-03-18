#include "solve_to_test_strategy.h"

#include <iostream>

using namespace std;

SolveToTestStrategy::SolveToTestStrategy(std::shared_ptr<Benchmark> bench)
    : benchmark(bench)
{}

string SolveToTestStrategy::solve(shared_ptr<Scheduler> scheduler, shared_ptr<PSP> psp)
{
    shared_ptr<POSL_Solver> solver = scheduler->getFirstSequentialSolver();
    if(solver)
    {
        solver->solve(psp);
        return solver->show(psp);
    }
    else return "POSL Meta-Solver: fail :/ (testing)";
}
