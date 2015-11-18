#include "om_ss_uncoder.h"
#include "../tools/tools.h"

#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_first_improvement_selection.h"

using namespace std;

OM_SS_Uncoder::OM_SS_Uncoder()
{
}

shared_ptr<OperationModule> OM_SS_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    Tools::trim(code);
    int pos_point = code.find('.');
    string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if(om_name == OM_BEST_IMPROVEMENT_SELECTION_TOK)
        return make_shared<OM_BestImprovementSelection>(bench);
    else if(om_name == OM_BEST_IMPROVEMENT_TABU_SELECTION_TOK)
        return make_shared<OM_BestImprovementTabuSelection>(bench);
    else if(om_name == OM_RANDOM_SELECTION_TOK)
        return make_shared<OM_RandomSelection>(bench);
    else if(om_name == OM_FIRST_IMPROVEMENT_SELECTION_TOK)
        return make_shared<OM_FirstImprovementSelection>(bench);
    else
        throw "(POSL Exception) OM does not exists (OM_SS_Uncoder::uncode)";
}
