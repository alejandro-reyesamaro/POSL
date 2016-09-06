#include "om_v_all_permutations_uncoder.h"
#include "../modules/om_all_permutations_neighborhood.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"

using namespace std;

OM_V_AllPermutations_Uncoder::OM_V_AllPermutations_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_AllPermutations_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    if(code.find("(") != std::string::npos)
    {
        pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
        int part = Tools::str2int(p.first);

        return make_shared<OM_AllPermutationsNeighborhood>(bench, part);
    }
    else
        throw "(POSL Exception) Not well coded OM_V (OM_V_ASPartial_Uncoder::uncode)";
    return nullptr;
}
