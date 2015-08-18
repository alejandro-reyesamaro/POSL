#include "psp.h"

PSP::PSP(int _argc, char **_argv, Benchmark * _bench, int _pID)
    : ARGC(_argc),
      ARGV(_argv),
      bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_solution(NULL),
      pID(_pID),
      comm(new Comunicator())
{}

PSP::PSP(int _argc, char **_argv, Benchmark * _bench)
    : PSP (_argc, _argv, _bench, -1)
{}

void PSP::UpdateSolution(Solution * solution)
{
    bench->UpdateSolution(solution);
    int cost = bench->solutionCost(solution);
    int best_cost = BestCostSoFar();
    if(best_found_solution == NULL || cost < best_cost)
        best_found_solution = solution;
}

int PSP::GetPID(){ return pID; }

Benchmark * PSP::GetBenchmark(){ return bench; }

int PSP::GetIterations(){ return iterations; }

int PSP::GetTime(){ return milisecs; }

Solution * PSP::GetBestSolutionSoFar(){ return best_found_solution; }

Solution * PSP::GetCurrentSolution(){ return bench->GetSolution(); }

int PSP::CurrentCost(){ return bench->solutionCost(bench->GetSolution()); }

int PSP::BestCostSoFar(){ return (best_found_solution == NULL)? -1 : bench->solutionCost(best_found_solution); }

void PSP::UpdateTime(int _milisecs){ milisecs = _milisecs; }

void PSP::CountIteration(){ iterations ++; }

void PSP::connectWith(int pID) { connections.push_back(pID); }

void PSP::SendData(Packable * data)
{
    for(vector<int>::iterator it = connections.begin(); it != connections.end(); ++it)
        comm->sendMessage(data, *it);
}
