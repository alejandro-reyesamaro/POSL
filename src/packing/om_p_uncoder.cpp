#include "om_p_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "om_r_tabu_uncoder.h"

using namespace std;

OM_P_Uncoder::OM_P_Uncoder()
{
}

shared_ptr<OperationModule> OM_P_Uncoder::uncode(string code,
                                                 shared_ptr<Benchmark> bench,
                                                 shared_ptr<SearchProcessParamsStruct> psp_params)
{
    CodingTools::trim(code);
    if(code.find(OM_TABU_CONFIGURATION_SET_PROCESSING_TOK) != std::string::npos)
    {
        OM_R_Tabu_Uncoder tabu_unc;
        return tabu_unc.uncode(code, bench, psp_params);
    }
    else
        throw "(POSL Exception) OM does not exists (OM_P_Uncoder::uncode)";
}
