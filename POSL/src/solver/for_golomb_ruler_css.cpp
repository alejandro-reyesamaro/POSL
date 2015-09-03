#include "for_golomb_ruler_css.h"

#include "../modules/om_random_conf_ordered_generation.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a002.h"
#include "../computation/factory_computation_strategy_sa002.h"
#include "../computation/factory_computation_strategy_ra002.h"

ForGolombRulerCSS::ForGolombRulerCSS(GolombRuler * golomb)
    : CreateSolverStrategy(golomb)
{}

vector<POSL_Solver *> ForGolombRulerCSS::create()
{
    /*
    FactoryComputationStrategy * fac_cs1 = new FactoryComputationStrategy_SA002
    (
        new OM_RandomConfOrderedGeneration(bench),
        new OM_OneSortedChangeNeighborhood(bench),
        new OM_MultiSortedChangesNeighborhood(bench),
        new OM_FirstImprovementSelection(bench),
        new OM_BestImprovementTabuSelection(bench),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.5, 20, 70, 40
    );
    FactoryComputationStrategy * fac_cs2 = new FactoryComputationStrategy_RA002
    (
        new OM_RandomConfOrderedGeneration(bench),
        new OM_OneSortedChangeNeighborhood(bench),
        new OM_MultiSortedChangesNeighborhood(bench),
        new OM_FirstImprovementSelection(bench),
        new OM_BestImprovementTabuSelection(bench),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.2, 20, 70, 40
    );
    */
    FactoryComputationStrategy * fac_cs = new FactoryComputationStrategy_A002
    (
        new OM_RandomConfOrderedGeneration(bench),
        new OM_OneSortedChangeNeighborhood(bench),
        new OM_MultiSortedChangesNeighborhood(bench),
        new OM_FirstImprovementSelection(bench),
        new OM_BestImprovementTabuSelection(bench),
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
