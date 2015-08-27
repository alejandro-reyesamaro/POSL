#include "uncode_operation_module_strategy.h"
#include "../tools/tools.h"

#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_florian_random_conf_generation.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_random_conf_ordered_generation.h"

#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"

#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_first_improvement_selection.h"

#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

UncodeOperationModuleStrategy::UncodeOperationModuleStrategy()
{}

OperationModule * UncodeOperationModuleStrategy::uncode(string code)
{
    trim(code);
    char L = code.front();
    int  N = Tools::str2int(code.substr(1));

    if(L == 'A') // FIRST CONFIGURATION GENERATION
    {
        switch(N)
        {
            case 1: // fixed first configuration
                return new OM_FixedFirstConfiguration();
                break;
            case 2: // random first configuration
                return new OM_RandomConfGeneration();
                break;
            case 3:

                break;
            case 4: // random permutation by blocks
                return new OM_RandomConfPermutationByBlocksGeneration();
                break;
            case 5: // random ordered permutation
                return new OM_RandomConfOrderedGeneration();
                break;
            default:
                throw "Not well coded OperationModule (First Configuration)";
        }
    }
    else if(L == 'B') // NEIGHBORHOOD
    {
        switch(N)
        {
            case 1: // one element change neighborhood
                return new OM_OneElementChangedNeighborhood();
                break;
            case 2: // multi elements change neighborhood
                return new OM_MultiElementsChangedNeighborhood();
                break;
            case 3: // golfers neighborhood
                return new OM_GolfersSingleSwapNeighborhood();
                break;
            case 4: // golom neighborhood (multi)
                return new OM_MultiSortedChangesNeighborhood();
                break;
            case 5: // golom neighborhood (one)
                return new OM_OneSortedChangeNeighborhood();
                break;
            default:
                throw "Not well coded OperationModule (Neighborhood)";
        }
    }
    else if(L == 'C') // SELECTION
    {
        switch(N)
        {
            case 1: // random selection
                return new OM_RandomSelection();
                break;
            case 2: // First Improvement selection
                return new OM_FirstImprovementSelection();
                break;
            case 3: // Best Improvement selection
                return new OM_BestImprovementSelection();
                break;
            case 4: // Best Improvement TABU selection
                return new OM_BestImprovementTabuSelection();
                break;
            default:
                throw "Not well coded OperationModule (Selection)";
        }
    }
    else if(L == 'D') // DECISSION
    {
        switch(N)
        {
            case 1: // always improve
                return new OM_AlwaysImproveDecision();
                break;
            case 2: // simulated annealing
                return new OM_SimulatedAnnealingDecision();
                break;
            default:
                throw "Not well coded OperationModule (Decission)";
        }
    }
    else
        throw "Not well coded OperationModule";
}
