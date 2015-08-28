#include "for_squaring_square_css.h"

#include "../modules/om_random_conf_generation.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a002.h"
#include "../computation/factory_computation_strategy_sa002.h"
#include "../computation/factory_computation_strategy_ra002.h"

ForSquaringSquareCSS::ForSquaringSquareCSS()
{}

vector<POSL_Solver *> ForSquaringSquareCSS::create()
{
    FactoryComputationStrategy * fac_cs1 = new FactoryComputationStrategy_SA002
    (
        new OM_RandomConfGeneration(),
        new OM_OneElementChangedNeighborhood(),
        new OM_MultiElementsChangedNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.5, 20, 70, 40
    );
    FactoryComputationStrategy * fac_cs2 = new FactoryComputationStrategy_RA002
    (
        new OM_RandomConfGeneration(),
        new OM_OneElementChangedNeighborhood(),
        new OM_MultiElementsChangedNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.2, 20, 70, 40
    );
    FactoryComputationStrategy * fac_cs = new FactoryComputationStrategy_A002
    (
        new OM_RandomConfGeneration(),
        new OM_OneElementChangedNeighborhood(),
        new OM_MultiElementsChangedNeighborhood(),
        new OM_FirstImprovementSelection(),
        new OM_BestImprovementTabuSelection(),
        new OM_SimulatedAnnealingDecision(),
        new OM_AlwaysImproveDecision(),
        0.5, 20, 200, 10
    );

    ComputationStrategy * cs1 = new ComputationStrategy(fac_cs1);
    POSL_Solver * solver_1 = new POSL_Solver(cs1);
    ComputationStrategy * cs2 = new ComputationStrategy(fac_cs2);
    POSL_Solver * solver_2 = new POSL_Solver(cs2);
    ComputationStrategy * cs3 = new ComputationStrategy(fac_cs);
    POSL_Solver * solver_3 = new POSL_Solver(cs3);

    vector<POSL_Solver *> solvers;
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(solver_3);

    return solvers;
}
