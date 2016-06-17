#include "grouped_sequential_computation_uncoder.h"
#include "operator_uncoder.h"

using namespace std;

GroupedSequentialComputationUncoder::GroupedSequentialComputationUncoder()
{}

shared_ptr<GroupedSequentialComputation> GroupedSequentialComputationUncoder::uncode(string code,
                                                                                     shared_ptr<Benchmark> bench,
                                                                                     shared_ptr<SearchProcessParamsStruct> psp_params)
{
    OperatorUncoder op_unc;
    return make_shared<GroupedSequentialComputation>(op_unc.uncode(code, bench, psp_params));
}
