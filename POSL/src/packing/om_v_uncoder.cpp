#include "om_v_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_one_permutation_neighborhood.h"

using namespace std;

OM_V_Uncoder::OM_V_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    //int pos_point = code.find('.');
    //string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if(code == OM_GOLFERS_SINGLE_SWAP_NEIGHBORHOOD_TOK)
        return make_shared<OM_GolfersSingleSwapNeighborhood>(bench);
    else if(code == OM_ONE_CHANGE_NEIHBORHOOD_TOK)
        return make_shared<OM_OneElementChangedNeighborhood>(bench);
    else if(code == OM_MULTI_CHANGES_NEIGHBORHOOD_TOK)
        return make_shared<OM_MultiElementsChangedNeighborhood>(bench);
    else if(code == OM_MULTI_SORTED_CHANGES_NEIGHBORHOOD_TOK)
        return make_shared<OM_MultiSortedChangesNeighborhood>(bench);
    else if(code == OM_ONE_SORTED_CHANGE_NEIGHBORHOOD_TOK)
        return make_shared<OM_OneSortedChangeNeighborhood>(bench);
    else if(code == OM_ONE_PERMUTATION_NEIGHBORHOOD_TOK)
        return make_shared<OM_OnePermutationNeighborhood>(bench);
    else
        throw "(POSL Exception) OM does not exists (OM_V_Uncoder::uncode)";
}
