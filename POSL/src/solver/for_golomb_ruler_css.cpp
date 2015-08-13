#include "for_golomb_ruler_css.h"

#include "../modules/om_random_conf_ordered_generation.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a002.h"

ForGolombRulerCSS::ForGolombRulerCSS()
{}

vector<POSL_Solver *> ForGolombRulerCSS::create()
{
    FactoryComputationStrategy * fac_cs = new FactroryComputationStrategy_A002
    (
        new OM_RandomConfOrderedGeneration(),
        new OM_OneSortedChangeNeighborhood(),
        new OM_MultiSortedChangesNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.5, 20, 500, 10
    );
    ComputationStrategy * cs = new ComputationStrategy(fac_cs);
    POSL_Solver * solver_1 = new POSL_Solver(cs);

    vector<POSL_Solver *> solvers;
    solvers.push_back(solver_1);

    return solvers;
}
