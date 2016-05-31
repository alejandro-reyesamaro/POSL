#include "om_r_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_default_processing.h"
#include "../modules/om_adaptive_search_processing.h"
#include "../modules/om_daniel_as_restart_processing.h"
#include "../modules/om_tabu_processing.h"

using namespace std;

OM_R_Uncoder::OM_R_Uncoder()
{
}

shared_ptr<OperationModule> OM_R_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);

    if(code == OM_DEFAULT_PROCESSING_TOK)
        return make_shared<OM_DefaultProcessing>();
    else if(code == OM_AS_PROCESSING_TOK)
        return make_shared<OM_AdaptiveSearchProcessing>(bench);
    else if(code == OM_DANIEL_PROCESSING_TOK)
        return make_shared<OM_DanielASRestartProcessing>();
    else if(code == OM_TABU_PROCESSING_TOK)
        return make_shared<OM_TabuProcessing>();
    else
        throw "(POSL Exception) OM does not exists (OM_R_Uncoder::uncode)";
}
