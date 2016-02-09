#include "om_d_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"
#include "operation_module_simulated_anealing_uncoder.h"

using namespace std;

OM_D_Uncoder::OM_D_Uncoder()
{
}

shared_ptr<OperationModule> OM_D_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    //int pos_point = code.find('.');
    //string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if(code == OM_ALWAYS_IMPROVEMENT_DECISION_TOK)
        return make_shared<OM_AlwaysImproveDecision>();
    else if(CodingTools::isInThere(code,OM_SIMULATED_ANNEALING_DECISION_TOK))
    {
        OperationModuleSimulatedAnealingUncoder sa_unc;
        return sa_unc.uncode(code, bench);
    }
    else
        throw "(POSL Exception) OM does not exists (OM_D_Uncoder::uncode)";
}
