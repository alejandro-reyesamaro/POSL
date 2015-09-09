#include "posl_solver.h"
#include "../tools/tools.h"
#include "../computation/flag_computation.h"

#include <iostream>
using namespace std;

POSL_Solver::POSL_Solver(shared_ptr<ComputationStrategy> _strategy)
    : final_solution(nullptr),
      best_solution(nullptr),
      final_cost(-1),
      best_cost(-1),
      iterations(-1),
      time(-1),
      strategy(_strategy)
{}


void POSL_Solver::solve(shared_ptr<PSP> psp)
{    
    final_solution = strategy->execute(psp);
    final_cost = psp->GetBenchmark()->solutionCost(final_solution);
    best_solution = psp->GetBestSolutionSoFar();
    best_cost = psp->GetBenchmark()->solutionCost(best_solution);
    iterations = psp->GetIterations();
    time = psp->GetTime();
}

string POSL_Solver::showSolution(string str_finalSol, string str_bestSol)
{
    string out = "Final Solution:\n";
    out += str_finalSol + "\n";
    out += "Final cost: " + Tools::int2str(final_cost) + "\n";
    out += "\n";
    out += "BEST Solution:\n";
    out += str_bestSol + "\n";
    out += "BEST cost: " + Tools::int2str(best_cost) + "\n";
    out += "\n";
    out += "Iterations: " + Tools::int2str(iterations) + "\n";
    out += "Time (milisecs): " + Tools::int2str(time);
    return out;
}

string POSL_Solver::show(shared_ptr<Benchmark> bench)
{
    if(final_solution != nullptr && best_solution != nullptr){
        string str_finalSol = bench->ShowSolution(final_solution);
        string str_bestSol = bench->ShowSolution(best_solution);
        return showSolution(str_finalSol, str_bestSol);
    }
    else return "Solver not working";
}

string POSL_Solver::show()
{
    if(final_solution != nullptr && best_solution != nullptr){
        string str_finalSol = final_solution->configurationToString();
        string str_bestSol = best_solution->configurationToString();
        return showSolution(str_finalSol, str_bestSol);
    }
    else return "Solver not working";
}
