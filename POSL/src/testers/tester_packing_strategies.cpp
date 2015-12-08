#include "tester_packing_strategies.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/aom_selection_function.h"
#include "../modules/aom_decision_function.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_simulated_annealing_decision.h"

#include <algorithm>

Tester_PackingStrategies::Tester_PackingStrategies(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingStrategies::test()
{
    /*
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<FactoryComputationStrategy_B001> fc( make_shared<FactoryComputationStrategy_B001>
    (
        bench,
        make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench),
        make_shared<OM_GolfersSingleSwapNeighborhood>(bench),
        make_shared<OM_FirstImprovementSelection>(bench),
        make_shared<OM_RandomSelection>(bench),
        make_shared<OM_AlwaysImproveDecision>(),
        300,30
    ));
    shared_ptr<CompoundModule> cm = fc->buildModule();
    cout << cm->codeToSend() << endl;
    */
    return "deprecated ;)";
}
