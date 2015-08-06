#include "posl_solver.h"
#include "../tools/tools.h"
#include "../computation/flag_computation.h"

#include <iostream>
using namespace std;

POSL_Solver::POSL_Solver(int _argc, char **_argv,
                         Benchmark *_bench,
                         CreateSolverStrategy * create_strategy)
    : final_solution(NULL),
      best_solution(NULL),
      final_cost(-1),
      best_cost(-1),
      //psp(NULL),
      module(create_strategy->create())
{
    psp = new PSP(_argc, _argv, _bench, new FlagSequentialComputation());
}

POSL_Solver::POSL_Solver(int _argc, char **_argv,
                         Benchmark *_bench,
                         CreateSolverStrategy * create_strategy,
                         int procA, int procB, int procID)
    : final_solution(NULL),
      best_solution(NULL),
      final_cost(-1),
      best_cost(-1),
      //psp(NULL),
      module(create_strategy->create())
{
    if(procA != procID && procB != procID)
        throw "(POSL Exception) Not properly initializaction parallel solver";
    psp = new PSP(_argc, _argv, _bench, new FlagParallelComputation(procA, procB));
}









POSL_Solver::POSL_Solver(PSP * _psp, CreateSolverStrategy * create_strategy)
    : final_solution(NULL),
      best_solution(NULL),
      final_cost(-1),
      best_cost(-1),
      psp(_psp),
      module(create_strategy->create())
{}

bool POSL_Solver::Initialized()
{
    return psp->computation() == SEQ
           || (psp->ProcessA() != -1 && psp->ProcessB() != -1);
}

void POSL_Solver::solve()
{
    if(Initialized())
    {
        final_solution = (Solution *)module->execute(psp, NULL);
        final_cost = psp->GetBenchmark()->solutionCost(final_solution);
        best_solution = psp->GetBestSolutionSoFar();
        best_cost = psp->GetBenchmark()->solutionCost(best_solution);
    }
}

string POSL_Solver::show()
{
    if(Initialized()){
        string out = "Final Solution:\n";
        out += psp->GetBenchmark()->ShowSolution(final_solution) + "\n";
        out += "Final cost: " + Tools::int2str(final_cost) + "\n";
        out += "\n";
        out += "BEST Solution:\n";
        out += psp->GetBenchmark()->ShowSolution(best_solution) + "\n";
        out += "BEST cost: " + Tools::int2str(best_cost) + "\n";
        out += "\n";
        out += "Iterations: " + Tools::int2str(psp->GetIterations()) + "\n";
        out += "Time (milisecs): " + Tools::int2str(psp->GetTime());
        return out;
    }
    else return "Solver not working";
}
