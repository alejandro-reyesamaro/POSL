#include "not_implemented_parallel_strategy.h"

using namespace std;

NotImplementedParallelStrategy::NotImplementedParallelStrategy()
{
}

shared_ptr<ComputationData> NotImplementedParallelStrategy::evaluate(shared_ptr<PSP>, shared_ptr<ComputationData>)
{
    throw "Parallel strategy not supported";
}
