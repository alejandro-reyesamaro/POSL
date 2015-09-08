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

ForNQueensCSS::ForNQueensCSS(shared_ptr<NQueens> nq)
    : CreateSolverStrategy(nq),
      sender_solver(make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_SA001>
        (
            bench,
            make_shared<OM_RandomPermutationGeneration>(bench),
            make_shared<OM_OnePermutationNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.5, 20, 500, 10
        )))),
      receiver_solver(make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_RA001>
        (
            bench,
            make_shared<OM_RandomPermutationGeneration>(bench),
            make_shared<OM_OnePermutationNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 500, 10
        )))),
      single_solver(make_shared<POSL_Solver>(make_shared<ComputationStrategy>(make_shared<FactoryComputationStrategy_A001>
        (
            bench,
            make_shared<OM_RandomPermutationGeneration>(bench),
            make_shared<OM_OnePermutationNeighborhood>(bench),
            make_shared<OM_FirstImprovementSelection>(bench),
            make_shared<OM_BestImprovementTabuSelection>(bench),
            make_shared<OM_SimulatedAnnealingDecision>(),
            make_shared<OM_AlwaysImproveDecision>(),
            0.2, 20, 100, 10
        ))))
{}

vector<shared_ptr<POSL_Solver> > ForNQueensCSS::create()
{    
    //solvers.push_back(solver_1);
    //solvers.push_back(solver_2);
    solvers.push_back(single_solver);
    return solvers;
}
