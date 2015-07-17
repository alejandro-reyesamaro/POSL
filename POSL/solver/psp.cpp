#include "psp.h"

PSP::PSP(int _argc, char **_argv, Benchmark * _bench) : bench(_bench), iterations(0), ARGC(_argc), ARGV(_argv)
{}

void PSP::UpdateBestSolution(Solution * sol)
{
    best_found_solution = sol;
}
void PSP::UpdateSolution(Solution * sol)
{
    bench->UpdateSolution(sol);
}

Benchmark * PSP::GetBenchmark()
{
    return bench;
}

int PSP::GetIterations()
{
    return iterations;
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
    return bench->solutionCost(best_found_solution);
}
