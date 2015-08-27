#include "for_squaring_square_css.h"

#include "../modules/om_florian_random_conf_generation.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a002.h"

ForSquaringSquareCSS::ForSquaringSquareCSS()
{}

vector<POSL_Solver *> ForSquaringSquareCSS::create()
{
    FactoryComputationStrategy * fac_cs = new FactoryComputationStrategy_A002
    (
        new OM_FlorianRandomConfGeneration(),
        new OM_OneElementChangedNeighborhood(),
        new OM_MultiElementsChangedNeighborhood(),
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
