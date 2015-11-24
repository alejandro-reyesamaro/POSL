#include "operation_module_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "om_s_uncoder.h"
#include "om_v_uncoder.h"
#include "om_ss_uncoder.h"
#include "om_d_uncoder.h"

#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"

using namespace std;

OperationModuleUncoder::OperationModuleUncoder()
{
}

shared_ptr<OperationModule> OperationModuleUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    string om_type = CodingTools::extractTypeFromToken(code);

    if(om_type == OM_S_TOK_TYPE) // FIRST CONFIGURATION GENERATION
    {
        OM_S_Uncoder oms_unc;
        return oms_unc.uncode(code, bench);
    }
    else if(om_type == OM_V_TOK_TYPE) // NEIGHBORHOOD
    {
        OM_V_Uncoder omv_unc;
        return omv_unc.uncode(code, bench);
    }
    else if(om_type == OM_SS_TOK_TYPE) // SELECTION
    {
        OM_SS_Uncoder omss_unc;
        return omss_unc.uncode(code, bench);
    }
    else if(om_type == OM_D_TOK_TYPE) // DECISSION
    {
        OM_D_Uncoder omd_unc;
        return omd_unc.uncode(code, bench);
    }
    else if(om_type == OMS_TOK_TYPE) // SPETIALS
    {
        CodingTools::trim(code);

        if(code == OMS_ITERATIONS_COUNTER_TOK)
            return make_shared<OMS_IterationsCounter>();
        else if(code == OMS_TIME_COUNTER_TOK)
            return make_shared<OMS_TimeCounter>();
        else
            throw "(POSL Exception) OMS does not exist (OperationModuleUncoder::uncode)";
    }
    else
        throw "(POSL Exception) Not well coded OperationModule (OperationModuleUncoder::uncode)";
}
