#include "for_n_queens_css.h"

#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"

#include "../modules/om_random_permutation_generation.h"
#include "../modules/om_one_permutation_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_first_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../computation/factory_computation_strategy_a001.h"
#include "../computation/factory_computation_strategy_sa001.h"
#include "../computation/factory_computation_strategy_ra001.h"

ForNQueensCSS::ForNQueensCSS(NQueens * nq)
    : CreateSolverStrategy(nq),
      sender_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_SA001
        (
            bench,
            new OM_RandomPermutationGeneration(bench),
            new OM_OnePermutationNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_RA001
        (
            bench,
            new OM_RandomPermutationGeneration(bench),
            new OM_OnePermutationNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.2, 20, 500, 10
        )))),
      single_solver(new POSL_Solver(new ComputationStrategy(new FactoryComputationStrategy_A001
        (
            bench,
            new OM_RandomPermutationGeneration(bench),
            new OM_OnePermutationNeighborhood(bench),
            new OM_FirstImprovementSelection(bench),
            new OM_BestImprovementTabuSelection(bench),
            new OM_SimulatedAnnealingDecision(),
            new OM_AlwaysImproveDecision(),
            0.2, 20, 100, 10
        ))))
{}

vector<POSL_Solver *> ForNQueensCSS::create()
{    
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);
    return solvers;
}
