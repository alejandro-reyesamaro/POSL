#include "min_crit_comparison.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <typeinfo>

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
    string object1_name = typeid(*d1).name();
    string object2_name = typeid(*d2).name();

    if(object1_name == object2_name)
    {
        // Asking for solution
        if(object1_name == "Solution")
            return compareSolutions((Solution *)d1, (Solution *)d2, psp->GetBenchmark());

        // Asking for DecisionPair
        if(object1_name == "DecisionPair")
            return comparePairs((DecisionPair *)d1, (DecisionPair *)d2, psp->GetBenchmark());

        // Asking for Neighborhoods
        if(object1_name == "Neighborhood")
            return compareNeighborhoods((Neighborhood *)d1, (Neighborhood *)d2);
    }
    throw "(POSL Exception) Not casting allowed (MinCritComparison.GetMin)";
}
