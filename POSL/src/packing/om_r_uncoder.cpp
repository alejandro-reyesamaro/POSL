#include "om_r_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_default_rearrange.h"
//#include "../modules/om_simulated_annealing_decision.h"

using namespace std;

OM_R_Uncoder::OM_R_Uncoder()
{
}

shared_ptr<OperationModule> OM_R_Uncoder::uncode(string code, shared_ptr<Benchmark>)
{
    CodingTools::trim(code);

    if(code == OM_DEFAULT_REARRANGEMENT_TOK)
        return make_shared<OM_DefaultRearrange>();
    //else if(code == OM_SIMULATED_ANNEALING_DECISION_TOK)
    //    return make_shared<OM_SimulatedAnnealingDecision>();
    else
        throw "(POSL Exception) OM does not exists (OM_R_Uncoder::uncode)";
}
