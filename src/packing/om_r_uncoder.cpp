#include "om_r_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_default_processing.h"
#include "../modules/om_adaptive_search_processing.h"
#include "../modules/om_daniel_as_restart_processing.h"
#include "om_r_tabu_uncoder.h"

using namespace std;

OM_R_Uncoder::OM_R_Uncoder()
{
}

shared_ptr<OperationModule> OM_R_Uncoder::uncode(string code,
                                                 shared_ptr<Benchmark> bench,
                                                 shared_ptr<SearchProcessParamsStruct> psp_params)
{
    CodingTools::trim(code);

    if(code == OM_DEFAULT_PROCESSING_TOK)
        return make_shared<OM_DefaultProcessing>();
    else if(code == OM_AS_PROCESSING_TOK)
        return make_shared<OM_AdaptiveSearchProcessing>(bench);
    else if(code == OM_DANIEL_PROCESSING_TOK)
        return make_shared<OM_DanielASRestartProcessing>();
    else if(code.find(OM_TABU_CONFIGURATION_PROCESSING_TOK) != std::string::npos)
    {
        OM_R_Tabu_Uncoder tabu_unc;
        return tabu_unc.uncode(code, bench, psp_params);
    }
    else
        throw "(POSL Exception) OM does not exists (OM_R_Uncoder::uncode)";
}
