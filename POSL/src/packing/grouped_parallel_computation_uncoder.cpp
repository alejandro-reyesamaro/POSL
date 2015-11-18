#include "grouped_parallel_computation_uncoder.h"
#include "operator_uncoder.h"

using namespace std;

GroupedParallelComputationUncoder::GroupedParallelComputationUncoder()
{}

shared_ptr<GroupedParallelComputation> GroupedParallelComputationUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    OperatorUncoder op_unc;
    return make_shared<GroupedParallelComputation>(op_unc.uncode(code, bench));
}
