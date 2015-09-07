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

ForSquaringSquareCSS::ForSquaringSquareCSS(SquaringSquare * ssq)
    : CreateSolverStrategy(ssq),
      sender_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_SA002
        (
            bench,
            new OM_RandomConfGeneration(bench),
            new OM_OneElementChangedNeighborhood(bench),
            new OM_MultiElementsChangedNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_RA002
        (
            bench,
            new OM_RandomConfGeneration(bench),
            new OM_OneElementChangedNeighborhood(bench),
            new OM_MultiElementsChangedNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.2, 20, 500, 10
        )))),
      single_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_A002
        (
            bench,
            new OM_RandomConfGeneration(bench),
            new OM_OneElementChangedNeighborhood(bench),
            new OM_MultiElementsChangedNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.2, 20, 100, 10
        ))))
{}

vector<POSL_Solver *> ForSquaringSquareCSS::create()
{
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);
    return solvers;
}
