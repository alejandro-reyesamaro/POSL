#include "compound_module_uncoder.h"
#include "../tools/coding_tools.h"
#include "grouped_sequential_computation_uncoder.h"
#include "grouped_parallel_computation_uncoder.h"
#include "operation_module_uncoder.h"
#include "open_channel_uncoder.h"

using namespace std;

CompoundModuleUncoder::CompoundModuleUncoder()
{}

shared_ptr<CompoundModule> CompoundModuleUncoder::uncode(string code,
                                                         shared_ptr<Benchmark> bench,
                                                         shared_ptr<SearchProcessParamsStruct> psp_params)
{
    pair<CM_type, string> info = CodingTools::extratModuleFromCM(code);
    if (info.first == SEQ_G)
    {
        GroupedSequentialComputationUncoder seq_unc;
        return seq_unc.uncode(info.second, bench, psp_params);
    }
    else if (info.first == PAR_G)
    {
        GroupedParallelComputationUncoder par_unc;
        return par_unc.uncode(info.second, bench, psp_params);
    }
    else if (info.first == OM)
    {
        OperationModuleUncoder oper_unc;
        return oper_unc.uncode(info.second, bench, psp_params);
    }
    else if (info.first == OCH)
    {
        OpenChannelUncoder och_unc;
        return och_unc.uncode(info.second, bench);
    }
    else
        throw "(POSL Exception) Not well coded Compound Module (CompoundModuleUncoder::uncode)";
}
