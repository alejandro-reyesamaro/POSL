#include "om_d_uncoder.h"
#include "../tools/tools.h"

#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

using namespace std;

OM_D_Uncoder::OM_D_Uncoder()
{
}

shared_ptr<OperationModule> OM_D_Uncoder::uncode(string code, shared_ptr<Benchmark>)
{
    Tools::trim(code);
    int pos_point = code.find('.');
    string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if(om_name == OM_ALWAYS_IMPROVEMENT_DECISION_TOK)
        return make_shared<OM_AlwaysImproveDecision>();
    else if(om_name == OM_SIMULATED_ANNEALING_DECISION_TOK)
        return make_shared<OM_SimulatedAnnealingDecision>();
    else
        throw "(POSL Exception) OM does not exists (OM_D_Uncoder::uncode)";
}
