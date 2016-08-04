#include "om_v_as_range_uncoder.h"
#include "../modules/om_adaptive_search_range_neighborhood.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"

using namespace std;

OM_V_ASRange_Uncoder::OM_V_ASRange_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_ASRange_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    if(code.find("(") != std::string::npos)
    {
        pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
        //! [1- Tabu list size, 2- tabu eps, 3- tabu norm]
        vector<string> params_vec = CodingTools::split_string(p.first, '-');
        int a = Tools::str2int(params_vec[0]);
        int b = Tools::str2int(params_vec[1]);

        return make_shared<OM_AdaptiveSearchRangeNeighborhood>(bench, a, b);
    }
    else
        throw "(POSL Exception) Not well coded OM_V (OM_V_ASRange_Uncoder::uncode)";
    return nullptr;
}
