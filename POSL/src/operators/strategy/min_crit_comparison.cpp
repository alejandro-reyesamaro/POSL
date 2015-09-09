#include "min_crit_comparison.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <typeinfo>
#include <iostream>

using namespace std;

MinCritComparison::MinCritComparison()
{}

shared_ptr<Solution> compareSolutions(shared_ptr<Solution> s1, shared_ptr<Solution> s2, shared_ptr<Benchmark> bench)
{
    int cost1 = bench->solutionCost(s1);
    int cost2 = bench->solutionCost(s2);    
    return (cost1 <= cost2) ? s1 : s2;
}

shared_ptr<DecisionPair> comparePairs(shared_ptr<DecisionPair> p1, shared_ptr<DecisionPair> p2, shared_ptr<Benchmark> bench)
{
    int cost1 = bench->solutionCost(p1->GetFound());
    int cost2 = bench->solutionCost(p2->GetFound());
    return (cost1 <= cost2) ? p1 : p2;
}

shared_ptr<Neighborhood> compareNeighborhoods(shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2)
{
    return (v1->size() <= v2->size()) ? v1 : v2;
}

shared_ptr<ComputationData> MinCritComparison::getMin(shared_ptr<ComputationData> d1, shared_ptr<ComputationData> d2, shared_ptr<PSP> psp)
{
    // Asking for solution
    if(static_pointer_cast<Solution>(d1) && static_pointer_cast<Solution>(d2))
        return compareSolutions(static_pointer_cast<Solution>(d1), static_pointer_cast<Solution>(d2), psp->GetBenchmark());
    // Asking for DecisionPair
    else if(static_pointer_cast<DecisionPair>(d1) && static_pointer_cast<DecisionPair>(d2))
        return comparePairs(static_pointer_cast<DecisionPair>(d1), static_pointer_cast<DecisionPair>(d2), psp->GetBenchmark());
    // Asking for Neighborhoods
    else if(static_pointer_cast<Neighborhood>(d1) && static_pointer_cast<Neighborhood>(d2))
        return compareNeighborhoods(static_pointer_cast<Neighborhood>(d1), static_pointer_cast<Neighborhood>(d2));

    throw "(POSL Exception) Not casting allowed (MinCritComparison.GetMin)";
}
