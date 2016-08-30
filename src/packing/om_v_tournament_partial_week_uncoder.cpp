#include "om_v_tournament_partial_week_uncoder.h"
#include "../modules/om_as_tournament_partial_neighborhood.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"

using namespace std;

OM_V_TournamentPartialWeek_Uncoder::OM_V_TournamentPartialWeek_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_TournamentPartialWeek_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    if(code.find("(") != std::string::npos)
    {
        pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
        //! [players, groups, part]
        vector<string> params_vec = CodingTools::split_string(p.first, '-');
        vector<int> int_params(params_vec.size(), 0);

        int d;
        for (unsigned int i = 0; i < int_params.size(); i++)
        {
            d = Tools::str2int(params_vec[i]);
            int_params[i] = d;
        }
        return make_shared<OM_ASTournamentPartialNeighborhood>(bench, int_params[0], int_params[1], int_params[2]);
    }
    else
        throw "(POSL Exception) Not well coded OM_V (OM_V_TournamentPartialWeek_Uncoder::uncode)";
    return nullptr;
}
