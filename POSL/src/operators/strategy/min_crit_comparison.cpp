#include "min_crit_comparison.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <typeinfo>
#include <iostream>

using namespace std;

MinCritComparison::MinCritComparison()
{}

Solution * compareSolutions(Solution * s1, Solution * s2, Benchmark * bench)
{
    int cost1 = bench->solutionCost(s1);
    int cost2 = bench->solutionCost(s2);    
    return (cost1 <= cost2) ? s1 : s2;
}

DecisionPair * comparePairs(DecisionPair * p1, DecisionPair * p2, Benchmark * bench)
{
    int cost1 = bench->solutionCost(p1->GetFound());
    int cost2 = bench->solutionCost(p2->GetFound());
    return (cost1 <= cost2) ? p1 : p2;
}

Neighborhood * compareNeighborhoods(Neighborhood * v1, Neighborhood * v2)
{
    return (v1->size() <= v2->size()) ? v1 : v2;
}

ComputationData * MinCritComparison::getMin(ComputationData * d1, ComputationData * d2, PSP * psp)
{
    // Asking for solution
    if(dynamic_cast<Solution *>(d1) && dynamic_cast<Solution *>(d2))
        return compareSolutions((Solution *)d1, (Solution *)d2, psp->GetBenchmark());
    // Asking for DecisionPair
    else if(dynamic_cast<DecisionPair *>(d1) && dynamic_cast<DecisionPair *>(d2))
        return comparePairs((DecisionPair *)d1, (DecisionPair *)d2, psp->GetBenchmark());
    // Asking for Neighborhoods
    else if(dynamic_cast<Neighborhood *>(d1) && dynamic_cast<Neighborhood *>(d2))
        return compareNeighborhoods((Neighborhood *)d1, (Neighborhood *)d2);

    throw "(POSL Exception) Not casting allowed (MinCritComparison.GetMin)";
}
