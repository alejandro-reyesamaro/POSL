#include "om_v_golfers_custom_week_uncoder.h"
#include "../modules/om_golfers_custom_week_swap_neighborhood.h"
#include "../modules/om_golfers_custom_week_adaptive_search_neighborhood.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"

using namespace std;

OM_V_GolfersCustomWeek_Uncoder::OM_V_GolfersCustomWeek_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_GolfersCustomWeek_Uncoder::uncode(string code, shared_ptr<Benchmark> bench, bool is_as)
{
    if(code.find("(") != std::string::npos)
    {
        pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
        //! [1- Tabu list size, 2- tabu eps, 3- tabu norm]
        vector<string> params_vec = CodingTools::split_string(p.first, '-');
        vector<int> weeks(params_vec.size(), 0);

        int week;
        for (unsigned int i = 0; i < weeks.size(); i++)
        {
            week = Tools::str2int(params_vec[i]);
            weeks[i] = week;
        }
        if (is_as)
          return make_shared<OM_GolfersCustomWeekAdaptiveSearchNeighborhood>(bench, weeks);
        else return make_shared<OM_GolfersCustomWeekSwapNeighborhood>(bench, weeks);
    }
    else
        throw "(POSL Exception) Not well coded OM_V (OM_V_GolfersCustomWeek_Uncoder::uncode)";
    return nullptr;
}
