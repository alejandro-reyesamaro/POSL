#include "om_ss_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_k_best_improvement_selection.h"

using namespace std;

OM_SS_Uncoder::OM_SS_Uncoder()
{
}

int is_kBest(string code);

shared_ptr<OperationModule> OM_SS_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    //int pos_point = code.find('.');
    //string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);
    int k = -1;
    if(code == OM_BEST_IMPROVEMENT_SELECTION_TOK)
        return make_shared<OM_BestImprovementSelection>(bench);
    else if(code == OM_BEST_IMPROVEMENT_TABU_SELECTION_TOK)
        return make_shared<OM_BestImprovementTabuSelection>(bench);
    else if(code == OM_RANDOM_SELECTION_TOK)
        return make_shared<OM_RandomSelection>(bench);
    else if(code == OM_FIRST_IMPROVEMENT_SELECTION_TOK)
        return make_shared<OM_FirstImprovementSelection>(bench);
    else if((k = is_kBest(code)) != -1)
        return make_shared<OM_KBestImprovementSelection>(bench, k);
    else
        throw "(POSL Exception) OM does not exists (OM_SS_Uncoder::uncode)";
}

int is_kBest(string code)
{
    string new_code = OM_KBEST_IMPROVEMENT_SELECTION_TOK;
    for(int i = 1; i < 10; i++)
    {
        // _num_
        new_code.replace(6, 5, Tools::int2str(i));
        if(new_code == code)
            return i;
        new_code = OM_KBEST_IMPROVEMENT_SELECTION_TOK;
    }
    return -1;
}
