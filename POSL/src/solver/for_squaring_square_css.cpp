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

ForSquaringSquareCSS::ForSquaringSquareCSS(shared_ptr<SquaringSquare> ssq)
    : CreateSolverStrategy(ssq),
      sender_solver(make_shared<POSL_Solver>(ssq, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_SA002>
        (
            bench,
            make_shared<OM_RandomConfGeneration>(bench),
            make_shared<OM_OneElementChangedNeighborhood>(bench),
            make_shared<OM_MultiElementsChangedNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(make_shared<POSL_Solver>(ssq, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_RA002>
        (
            bench,
            make_shared<OM_RandomConfGeneration>(bench),
            make_shared<OM_OneElementChangedNeighborhood>(bench),
            make_shared<OM_MultiElementsChangedNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 500, 10
        )))),
      single_solver(make_shared<POSL_Solver>(ssq, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_A002>
        (
            bench,
            make_shared<OM_RandomConfGeneration>(bench),
            make_shared<OM_OneElementChangedNeighborhood>(bench),
            make_shared<OM_MultiElementsChangedNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 100, 10
        ))))
{}

vector<shared_ptr<POSL_Solver> > ForSquaringSquareCSS::create()
{
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);
    return solvers;
}
