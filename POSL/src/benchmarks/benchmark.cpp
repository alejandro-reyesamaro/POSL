#include "benchmark.h"

Benchmark::Benchmark(vector<Domain> _domains)
    : domains(_domains)
{}

int Benchmark::solutionCost(Solution * sol){ return solutionCost(sol->GetConfiguration()); }

void Benchmark::UpdateSolution(Solution * sol){ solution = sol; }

Solution * Benchmark::GetSolution(){ return solution; }

vector<Domain> Benchmark::Domains(){ return domains; }
