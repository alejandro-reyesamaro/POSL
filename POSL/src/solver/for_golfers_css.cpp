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

ForGolfersCSS::ForGolfersCSS(shared_ptr<Golfers> golfers)
    : CreateSolverStrategy(golfers),
      sender_solver( make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_SA001>
        (
            bench,
            make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench),
            make_shared<OM_GolfersSingleSwapNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_RA001>
        (
            bench,
            make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench),
            make_shared<OM_GolfersSingleSwapNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 500, 10
        )))),
      single_solver(make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_A001>
        (
            bench,
            make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench),
            make_shared<OM_GolfersSingleSwapNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 100, 10
        ))))
{}

vector<shared_ptr<POSL_Solver> > ForGolfersCSS::create()
{
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);

    return solvers;
}
