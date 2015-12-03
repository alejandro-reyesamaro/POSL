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

ForGolombRulerCSS::ForGolombRulerCSS(shared_ptr<GolombRuler> golomb)
    : CreateSolverStrategy(golomb),
      sender_solver(make_shared<POSL_Solver>("s1", golomb, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_SA002>
        (
            bench,
            make_shared<OM_RandomConfOrderedGeneration>(bench),
            make_shared<OM_OneSortedChangeNeighborhood>(bench),
            make_shared<OM_MultiSortedChangesNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(make_shared<POSL_Solver>("s1", golomb, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_RA002>
        (
            bench,
            make_shared<OM_RandomConfOrderedGeneration>(bench),
            make_shared<OM_OneSortedChangeNeighborhood>(bench),
            make_shared<OM_MultiSortedChangesNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 500, 10
        )))),
      single_solver(make_shared<POSL_Solver>("s1",golomb, make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_A002>
        (
            bench,
            make_shared<OM_RandomConfOrderedGeneration>(bench),
            make_shared<OM_OneSortedChangeNeighborhood>(bench),
            make_shared<OM_MultiSortedChangesNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 100, 10
        ))))
{}

vector<shared_ptr<POSL_Solver> > ForGolombRulerCSS::create()
{
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);
    return solvers;
}
