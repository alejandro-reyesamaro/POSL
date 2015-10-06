#include "min_crit_comparison.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <typeinfo>
#include <iostream>

using namespace std;

MinCritComparison::MinCritComparison()
{}

bool compareSolutions(shared_ptr<Solution> s1, shared_ptr<Solution> s2, shared_ptr<Benchmark> bench)
{
    int cost1 = bench->solutionCost(s1);
    int cost2 = bench->solutionCost(s2);
    return (cost1 <= cost2);
}

shared_ptr<Solution> GetComparedSolutions(shared_ptr<Solution> s1, shared_ptr<Solution> s2, shared_ptr<Benchmark> bench)
{
    return (compareSolutions(s1, s2, bench)) ? s1 : s2;
}

bool comparePairs(shared_ptr<DecisionPair> p1, shared_ptr<DecisionPair> p2, shared_ptr<Benchmark> bench)
{
    int cost1 = bench->solutionCost(p1->GetFound());
    int cost2 = bench->solutionCost(p2->GetFound());
    cout << cost1 << cost2 << endl;
    return (cost1 <= cost2);
}

shared_ptr<DecisionPair> GetComparedPairs(shared_ptr<DecisionPair> p1, shared_ptr<DecisionPair> p2, shared_ptr<Benchmark> bench)
{
    return (comparePairs(p1, p2, bench)) ? p1 : p2;
}

bool compareNeighborhoods(shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2)
{
    return (v1->size() <= v2->size());
}

shared_ptr<Neighborhood> GetComparedNeighborhoods(shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2)
{
    return (compareNeighborhoods(v1, v2)) ? v1 : v2;
}

shared_ptr<ComputationData> MinCritComparison::getMin(shared_ptr<ComputationData> d1, shared_ptr<ComputationData> d2, shared_ptr<PSP> psp)
{
    // Asking for solution    
    if(d1->Tag() == TAGSOLUTION && d2->Tag() == TAGSOLUTION)
        return GetComparedSolutions(static_pointer_cast<Solution>(d1), static_pointer_cast<Solution>(d2), psp->GetBenchmark());
    // Asking for DecisionPair
    else if(d1->Tag() == TAGDECISSIONPAIR && d2->Tag() == TAGDECISSIONPAIR)
        return GetComparedPairs(static_pointer_cast<DecisionPair>(d1), static_pointer_cast<DecisionPair>(d2), psp->GetBenchmark());
    // Asking for Neighborhoods
    else if(d1->Tag() == TAGNEIGHBORHOOD && d2->Tag() == TAGNEIGHBORHOOD)
        return GetComparedNeighborhoods(static_pointer_cast<Neighborhood>(d1), static_pointer_cast<Neighborhood>(d2));
    throw "(POSL Exception) Not casting allowed (MinCritComparison.GetMin)";
}

bool MinCritComparison::isLessThan(shared_ptr<ComputationData> d1, shared_ptr<ComputationData> d2, shared_ptr<PSP> psp)
{
    // Asking for solution
    if(d1->Tag() == TAGSOLUTION && d2->Tag() == TAGSOLUTION)
        return compareSolutions(static_pointer_cast<Solution>(d1), static_pointer_cast<Solution>(d2), psp->GetBenchmark());
    // Asking for DecisionPair
    else if(d1->Tag() == TAGDECISSIONPAIR && d2->Tag() == TAGDECISSIONPAIR)
        return comparePairs(static_pointer_cast<DecisionPair>(d1), static_pointer_cast<DecisionPair>(d2), psp->GetBenchmark());
    // Asking for Neighborhoods
    else if(d1->Tag() == TAGNEIGHBORHOOD && d2->Tag() == TAGNEIGHBORHOOD)
        return compareNeighborhoods(static_pointer_cast<Neighborhood>(d1), static_pointer_cast<Neighborhood>(d2));
    throw "(POSL Exception) Not casting allowed (MinCritComparison.isLessThan)";
}
