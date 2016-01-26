#include "om_r_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_default_rearrange.h"
#include "../modules/om_adaptive_search_rearrenge.h"
#include "../modules/om_daniel_as_restart_rearrange.h"

using namespace std;

OM_R_Uncoder::OM_R_Uncoder()
{
}

shared_ptr<OperationModule> OM_R_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);

    if(code == OM_DEFAULT_REARRANGEMENT_TOK)
        return make_shared<OM_DefaultRearrange>();
    else if(code == OM_AS_REARRANGEMENT_TOK)
        return make_shared<OM_AdaptiveSearchRearrenge>(bench);
    else if(code == OM_DANIEL_REARRANGEMENT_TOK)
        return make_shared<OM_DanielASRestartRearrange>();
    else
        throw "(POSL Exception) OM does not exists (OM_R_Uncoder::uncode)";
}
