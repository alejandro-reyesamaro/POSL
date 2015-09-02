#include "for_golfers_css.h"

#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a001.h"
#include "../computation/factory_computation_strategy_sa001.h"
#include "../computation/factory_computation_strategy_ra001.h"

ForGolfersCSS::ForGolfersCSS()
{}

vector<POSL_Solver *> ForGolfersCSS::create()
{
    /*
    FactoryComputationStrategy * fac_cs1 = new FactoryComputationStrategy_SA001
    (
        new OM_RandomConfPermutationByBlocksGeneration(),
        new OM_GolfersSingleSwapNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.5, 20, 500, 10
    );
    FactoryComputationStrategy * fac_cs2 = new FactoryComputationStrategy_RA001
    (
        new OM_RandomConfPermutationByBlocksGeneration(),
        new OM_GolfersSingleSwapNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.2, 20, 500, 10
    );
    */
    FactoryComputationStrategy * fac_cs = new FactoryComputationStrategy_A001
    (
        new OM_RandomConfPermutationByBlocksGeneration(),
        new OM_GolfersSingleSwapNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.2, 20, 100, 10
    );
    //ComputationStrategy * cs1 = new ComputationStrategy(fac_cs1);
    //POSL_Solver * solver_1 = new POSL_Solver(cs1);
    //ComputationStrategy * cs2 = new ComputationStrategy(fac_cs2);
    //POSL_Solver * solver_2 = new POSL_Solver(cs2);
    ComputationStrategy * cs3 = new ComputationStrategy(fac_cs);
    POSL_Solver * solver_3 = new POSL_Solver(cs3);

    vector<POSL_Solver *> solvers;
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(solver_3);

    return solvers;
}
