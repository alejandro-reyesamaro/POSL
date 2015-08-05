#include "psp.h"

PSP::PSP(int _argc, char **_argv, Benchmark * _bench, FlagComputation *_computation)
    : ARGC(_argc),
      ARGV(_argv),
      bench(_bench),
      comp(_computation),
      iterations(0),
      milisecs(0),
      best_found_solution(NULL)
{}

PSP::PSP(int _argc, char **_argv, Benchmark * _bench)
    : PSP(_argc, _argv, _bench, new FlagSequentialComputation())
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

FlagParallelComputation * PSP::CastToParallelCOmputation()
{
    return (FlagParallelComputation *) comp;
}

Computation PSP::computation()
{
    return comp->computation();
}

/*
void PSP::SetProccesA(int procID)
{
    if(computation->computation() == PAR && procID >= 0)
        CastToParallelCOmputation()->ProcessA = procID;
}

void PSP::SetProccesB(int procID)
{
    if(computation->computation() == PAR && procID >= 0)
        CastToParallelCOmputation()->ProcessB = procID;
}
*/

int PSP::ProcessA()
{
    if (comp->computation() == PAR)
    {
        if (CastToParallelCOmputation()->ProcessA == -1)
            throw "(POSL Exception) not in parallel mode";
        return CastToParallelCOmputation()->ProcessA;
    }
    else return -1;
}

int PSP::ProcessB()
{
    if (comp->computation() == PAR)
    {
        if (CastToParallelCOmputation()->ProcessB == -1)
            throw "(POSL Exception) not in parallel mode";
        return CastToParallelCOmputation()->ProcessB;
    }
    else return -1;
}
