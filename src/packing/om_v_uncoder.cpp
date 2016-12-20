#include "om_v_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"

#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_one_sorted_change_companion_neighborhood.h"
#include "../modules/om_one_worst_sorted_neighborhood.h"
#include "../modules/om_one_permutation_neighborhood.h"
#include "../modules/om_all_permutations_neighborhood.h"
#include "../modules/om_adaptive_search_neighborhood.h"
#include "../modules/om_golfers_adaptive_search_neigborhood.h"
#include "../modules/om_subsum_single_permutation_neighborhood.h"
#include "../modules/om_one_2d_change_neighborhood.h"

#include "om_v_golfers_custom_week_uncoder.h"
#include "om_v_tournament_partial_week_uncoder.h"
#include "om_v_as_range_uncoder.h"
#include "om_v_as_partial_uncoder.h"
#include "om_v_all_permutations_uncoder.h"

using namespace std;

//int is_golfers_week(string code);
//int is_golfers_AS_week(string code);


OM_V_Uncoder::OM_V_Uncoder()
{
}

shared_ptr<OperationModule> OM_V_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    //int pos_point = code.find('.');
    //string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);
    //int w = -1;
    if(code == OM_GOLFERS_SINGLE_SWAP_NEIGHBORHOOD_TOK)
        return make_shared<OM_GolfersSingleSwapNeighborhood>(bench);
    else if(code == OM_ONE_CHANGE_NEIHBORHOOD_TOK)
        return make_shared<OM_OneElementChangedNeighborhood>(bench);
    else if(code == OM_MULTI_CHANGES_NEIGHBORHOOD_TOK)
        return make_shared<OM_MultiElementsChangedNeighborhood>(bench);
    else if(code == OM_MULTI_SORTED_CHANGES_NEIGHBORHOOD_TOK)
        return make_shared<OM_MultiSortedChangesNeighborhood>(bench);
    else if(code == OM_ONE_WORST_SORTED_CHANGE_NEIGHBORHOOD_TOK)
        return make_shared<OM_OneWorstSortedNeighborhood>(bench);
    else if(code == OM_SUBSUM_SINGLE_SWAP_NEIGHBORHOOD_TOK)
        return make_shared<OM_SubsumSinglePermutationNeighborhood>(bench);
    else if(code == OM_ONE_SORTED_CHANGE_NEIGHBORHOOD_TOK)
        return make_shared<OM_OneSortedChangeNeighborhood>(bench);
    else if(code == OM_ONE_SORTED_CHANGE_COMPANION_NEIGHBORHOOD_TOK)
        return make_shared<OM_OneSortedChangeCompanionNeighborhood>(bench);
    else if(code == OM_ONE_PERMUTATION_NEIGHBORHOOD_TOK)
        return make_shared<OM_OnePermutationNeighborhood>(bench);
    else if(code.find(OM_ALL_PERMUTATIONS_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_AllPermutations_Uncoder allpermut_unc;
        return allpermut_unc.uncode(code, bench);
    }
    else if(code == OM_ONE_2DCHANGE_NEIHBORHOOD_TOK)
        return make_shared<OM_One2DChangeNeighborhood>(bench);
    else if(code == OM_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK)
        return make_shared<OM_AdaptiveSearchNeighborhood>(bench);
    else if(code == OM_GOLFERS_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK)
        return make_shared<OM_GolfersAdaptiveSearchNeigborhood>(bench);
    else if(code.find(OM_GOLFERS_CUSTOM_WEEK_SWAP_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_GolfersCustomWeek_Uncoder custom_week_unc;
        return custom_week_unc.uncode(code, bench, false);
    }
    else if(code.find(OM_GOLFERS_CUSTOM_WEEK_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_GolfersCustomWeek_Uncoder custom_week_unc;
        return custom_week_unc.uncode(code, bench, true);
    }    
    else if(code.find(OM_TOURNAMENT_PARTIAL_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_TournamentPartialWeek_Uncoder partial_week_unc;
        return partial_week_unc.uncode(code, bench);
    }
    else if(code.find(OM_ADAPTIVE_SEARCH_RANGE_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_ASRange_Uncoder as_range_unc;
        return as_range_unc.uncode(code, bench);
    }
    else if(code.find(OM_ADAPTIVE_SEARCH_PARTIAL_NEIGHBORHOOD_TOK) != std::string::npos)
    {
        OM_V_ASPartial_Uncoder as_partial_unc;
        return as_partial_unc.uncode(code, bench);
    }
    else
        throw "(POSL Exception) OM does not exists (OM_V_Uncoder::uncode)";
}

/*
int is_golfers_week(string code)
{
    string new_code = OM_GOLFERS_SINGLE_WEEK_SWAP_NEIGHBORHOOD_TOK;
    for(int i = 1; i < 15; i++)
    {
        // _num_
        new_code.replace(5, 5, Tools::int2str(i));
        if(new_code == code)
            return i;
        new_code = OM_GOLFERS_SINGLE_WEEK_SWAP_NEIGHBORHOOD_TOK;
    }
    return -1;
}

int is_golfers_AS_week(string code)
{
    string new_code = OM_GOLFERS_SINGLE_WEEK_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;
    for(int i = 1; i < 15; i++)
    {
        // _num_
        new_code.replace(5, 5, Tools::int2str(i));
        if(new_code == code)
            return i;
        new_code = OM_GOLFERS_SINGLE_WEEK_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;
    }
    return -1;
}
*/
