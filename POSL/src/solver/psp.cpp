#include "psp.h"

PSP::PSP(int _argc, char **_argv, Benchmark * _bench)
    : ARGC(_argc),
      ARGV(_argv),
      bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_solution(NULL)
{}

void PSP::UpdateSolution(Solution * solution)
{
    bench->UpdateSolution(solution);
    if(best_found_solution == NULL || bench->solutionCost(solution) < BestCostSoFar())
        best_found_solution = solution;
}

Benchmark * PSP::GetBenchmark()
{
    return bench;
}

int PSP::GetIterations()
{
    return iterations;
}

int PSP::GetTime()
{
    return milisecs;
}

Solution * PSP::GetBestSolutionSoFar()
{
    return best_found_solution;
}

Solution * PSP::GetCurrentSolution()
{
    return bench->GetSolution();
}

int PSP::CurrentCost()
{
    return bench->solutionCost(bench->GetSolution());
}

int PSP::BestCostSoFar()
{
    return (best_found_solution == NULL)
        ? -1
        : bench->solutionCost(best_found_solution);
}

void PSP::UpdateTime(int _milisecs)
{
    milisecs = _milisecs;
}

void PSP::CountIteration()
{
    iterations ++;
}
