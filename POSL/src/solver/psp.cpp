#include "psp.h"

PSP::PSP(int _argc, char **_argv, shared_ptr<Benchmark> _bench, int _pID)
    : ARGC(_argc),
      ARGV(_argv),
      bench(_bench),
      iterations(0),
      milisecs(0),
      best_found_solution(nullptr),
      pID(_pID),
      comm(make_shared<Comunicator>())
{}

PSP::PSP(int _argc, char **_argv, shared_ptr<Benchmark> _bench)
    : PSP (_argc, _argv, _bench, -1)
{}

void PSP::UpdateSolution(shared_ptr<Solution> solution)
{
    bench->UpdateSolution(solution);
    int cost = bench->solutionCost(solution);
    int best_cost = BestCostSoFar();
    if(best_found_solution == nullptr || cost < best_cost)
        best_found_solution = solution;
}

void PSP::UpdateTime(int _milisecs){ milisecs = _milisecs; }

void PSP::CountIteration(){ iterations ++; }

void PSP::connectWith(int pID) { connections.push_back(pID); }

void PSP::SendData(vector<int> data)
{
    for(vector<int>::iterator it = connections.begin(); it != connections.end(); ++it)
        comm->sendMessage(data, *it);
}
