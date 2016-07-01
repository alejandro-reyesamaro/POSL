#include "om_r_tabu_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"

using namespace std;

OM_R_Tabu_Uncoder::OM_R_Tabu_Uncoder()
{
}

std::shared_ptr<OM_TabuConfigurationProcessing> OM_R_Tabu_Uncoder::uncode(string code,
                                                                          shared_ptr<Benchmark>,
                                                                          shared_ptr<SearchProcessParamsStruct> psp_params)
{
    if(code.find("(") != std::string::npos)
    {
        pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
        //! [1- Tabu list size, 2- tabu eps, 3- tabu norm]
        vector<string> params_vec = CodingTools::split_string(p.first, ':');

        int tabu_list_size = Tools::str2int(params_vec[0]);
        float eps = Tools::str2float(params_vec[1]);
        int tabu_norm = Tools::str2int(params_vec[2]);

        psp_params->SetTabuListSize(tabu_list_size);
        psp_params->SetTabuEps(eps);
        psp_params->SetTabuNormType(tabu_norm);
    }
    return make_shared<OM_TabuConfigurationProcessing>();
}
