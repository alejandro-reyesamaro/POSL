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
    cout << "comparing between " << cost1 << " and " << cost2 << endl;
    return (cost1 <= cost2) ? p1 : p2;
}

Neighborhood * compareNeighborhoods(Neighborhood * v1, Neighborhood * v2)
{
    return (v1->size() <= v2->size()) ? v1 : v2;
}

ComputationData * MinCritComparison::getMin(ComputationData * d1, ComputationData * d2, PSP * psp)
{
    //string object1_name = typeid(*d1).name();
    //string object2_name = typeid(*d2).name();
    //cout << object1_name << " ... " << object2_name << endl;

    // Asking for solution
    Solution * s1_object = dynamic_cast<Solution *>(d1);
    Solution * s2_object = dynamic_cast<Solution *>(d2);
    if(s1_object && s2_object)
        return compareSolutions((Solution *)d1, (Solution *)d2, psp->GetBenchmark());

    // Asking for DecisionPair
    DecisionPair * p1_object = dynamic_cast<DecisionPair *>(d1);
    DecisionPair * p2_object = dynamic_cast<DecisionPair *>(d2);
    if(p1_object && p2_object)
        return comparePairs((DecisionPair *)d1, (DecisionPair *)d2, psp->GetBenchmark());

    // Asking for Neighborhoods
    Neighborhood * v1_object = dynamic_cast<Neighborhood *>(d1);
    Neighborhood * v2_object = dynamic_cast<Neighborhood *>(d2);
    if(v1_object && v2_object)
        return compareNeighborhoods((Neighborhood *)d1, (Neighborhood *)d2);

    throw "(POSL Exception) Not casting allowed (MinCritComparison.GetMin)";
}
