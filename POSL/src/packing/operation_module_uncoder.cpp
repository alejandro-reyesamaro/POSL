#include "operation_module_uncoder.h"
#include "../tools/tools.h"

#include "om_s_uncoder.h"
#include "om_v_uncoder.h"
#include "om_ss_uncoder.h"
#include "om_d_uncoder.h"

using namespace std;

OperationModuleUncoder::OperationModuleUncoder()
{
}

shared_ptr<OperationModule> OperationModuleUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    Tools::trim(code);
    string om_type = code.substr(0, code.find('.'));

    if(om_type == "OM_S") // FIRST CONFIGURATION GENERATION
    {
        OM_S_Uncoder oms_unc;
        return oms_unc.uncode(code, bench);
    }
    else if(om_type == "OM_V") // NEIGHBORHOOD
    {
        OM_V_Uncoder omv_unc;
        return omv_unc.uncode(code, bench);
    }
    else if(om_type == "OM_SS") // SELECTION
    {
        OM_SS_Uncoder omss_unc;
        return omss_unc.uncode(code, bench);
    }
    else if(om_type == "OM_D") // DECISSION
    {
        OM_D_Uncoder omd_unc;
        return omd_unc.uncode(code, bench);
    }
    else
        throw "(POSL Exception) Not well coded OperationModule (OperationModuleUncoder::uncode)";
}
