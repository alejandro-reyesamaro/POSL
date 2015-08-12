#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "testers/tester.h"
#include "testers/tester_cost_of_solution_golfers.h"
#include "testers/tester_cost_of_solution_quaring_square.h"
#include "testers/tester_cost_of_solution_golom_rules.h"
#include "testers/tester_random_configuration_generation.h"
#include "testers/tester_random_ordered_confgeneration.h"
#include "testers/tester_florian_random_configuration_generation.h"
#include "testers/tester_one_element_changed_neighborhood.h"
#include "testers/tester_first_improvement_selection.h"
#include "testers/tester_best_improvement_selection.h"
#include "testers/tester_rho_operator.h"
#include "testers/tester_cyclic_operator.h"
#include "testers/tester_sets_index_generator.h"
#include "testers/tester_multi_elements_changed_neighborhood.h"
#include "testers/tester_multi_sorted_changes_neighborhood.h"
#include "testers/tester_one_sorted_change_neighborhood.h"
#include "testers/tester_union_operator.h"
#include "testers/tester_conditional_operator.h"
#include "testers/tester_random_selection.h"
#include "testers/tester_simulated_annealing_decition.h"
#include "testers/tester_best_improvement_tabu_selection.h"
#include "testers/tester_random_permutation_configuration_generation.h"
#include "testers/tester_golfers_permutation_neighborhood.h"
#include "testers/tester_packing_solution.h"
#include "testers/tester_packing_decision_pair.h"
#include "testers/tester_packing_one_element_changed_neighborhood.h"
#include "testers/tester_packing_multi_changes_neighborhood.h"
#include "testers/tester_packing_golfers_permutation_neighborhood.h"
#include "testers/tester_packing_union_neighborhood.h"
#include "testers/tester_packing_union_neighborhood.h"
#include "testers/tester_union_operator.h"
#include "testers/tester_speed_operator.h"
#include "testers/tester_coding_compound_modules.h"
#include "testers/tester_solver_golfers.h"
#include "testers/tester_solver_golomb_ruler.h"
#include "testers/tester_solver_squaring_square.h"
#include "solver/for_golfers_css.h"
#include "solver/for_squaring_square_css.h"
#include "solver/for_golomb_ruler_css.h"

#include "solver/posl_meta_solver.h"

#include "mpi.h"

using namespace std;

// Testing SEQUENTIAL
int main(int argc, char **argv)
{
    vector<Tester *> tests;


    //tests.push_back(new Tester_CostOfSolutionGolfers(argc, argv));
    //tests.push_back(new Tester_CostOfSolutionSquaringSquare(argc, argv));
    tests.push_back(new Tester_CostOfSolutionGolomRules(argc, argv));
    //tests.push_back(new Tester_RandomOrderedConfGeneration(argc, argv));
    //tests.push_back(new Tester_MultiSortedChangesNeighborhood(argc, argv));
    //tests.push_back(new Tester_OneSortedChangeNeighborhood(argc, argv));
    /*
    tests.push_back(new Tester_RandomConfigurationGeneration(argc, argv));
    tests.push_back(new Tester_FlorianRandomConfigurationGeneration(argc, argv));
    tests.push_back(new Tester_OneElementChangedNeighborhood(argc, argv));
    tests.push_back(new Tester_FirstImprovementSelection(argc, argv));
    tests.push_back(new Tester_BestImprovementSelection(argc, argv));
    tests.push_back(new Tester_RhoOperator(argc, argv));
    //tests.push_back(new Tester_CyclicOperator(argc, argv));
    tests.push_back(new Tester_SetsIndexGenerator(argc, argv));
    tests.push_back(new Tester_MultiElementsChangedNeighborhood(argc, argv));    
    tests.push_back(new Tester_ConditionalOperator(argc, argv));
    tests.push_back(new Tester_RandomSelection(argc, argv));
    tests.push_back(new Tester_SimulatedAnnealingDecition(argc, argv));
    tests.push_back(new Tester_BestImprovementTabuSelection(argc, argv));
    tests.push_back(new Tester_RandomPermutationConfigurationGeneration(argc, argv));
    tests.push_back(new Tester_GolfersPermutationNeighborhood(argc, argv));
    tests.push_back(new Tester_PackingSolution(argc, argv));
    tests.push_back(new Tester_PackingDecisionPair(argc, argv));
    tests.push_back(new Tester_PackingOneElementChangedNeighborhood(argc, argv));
    tests.push_back(new Tester_PackingMultiChangesNeighborhood(argc, argv));
    tests.push_back(new Tester_PackingGolfersPermutationNeighborhood(argc, argv));
    tests.push_back(new Tester_PackingUnionNeighborhood(argc, argv));
    tests.push_back(new Tester_CodingCompoundModules(argc, argv));
    */
    //tests.push_back(new Tester_Solver_Golfers(argc, argv));
    tests.push_back(new Tester_Solver_GolombRuler(argc, argv));
    //tests.push_back(new Tester_SolverSquaringSquare(argc, argv));

    string output_str;
    for(unsigned int i = 0; i < tests.size(); i++)
    {
        output_str = tests[i]->test();
        cout << ">> " << output_str << endl;
    }
}

// Testing PARALLEL
int mainNOO(int argc, char **argv)
{
    vector<Tester *> tests;

    //tests.push_back(new Tester_UnionOperator(argc, argv));
    tests.push_back(new Tester_SpeedOperator(argc, argv));

    int tester_id;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &tester_id);

    string output_str;
    for(unsigned int i = 0; i < tests.size(); i++)
    {
        output_str = tests[i]->test();
        cout << ">> " << output_str << endl;
    }

    MPI_Finalize();
}

int mainNO(int argc, char **argv)
{

    vector<POSL_Solver *> solvers;
    Benchmark * bench;

    /* GOLFERS
    bench = new Golfers(5,5,3);
    POSL_Solver * solver_1 = new POSL_Solver(new ForGolfersCSS());
    POSL_Solver * solver_2 = new POSL_Solver(new ForGolfersCSS());
    */

    /* SQUARING SQUARE
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    bench = new SquaringSquare(10,squares);
    POSL_Solver * solver_1 = new POSL_Solver(new ForSquaringSquareCSS());
    */

    /* GOLOMB RULER */
    bench = new GolombRuler(12,85);
    POSL_Solver * solver_1 = new POSL_Solver(new ForGolombRulerCSS());

    solvers.push_back(solver_1);
    POSL_MetaSolver * s = new POSL_MetaSolver(solvers);
    s->solve(argc, argv, bench);
}


// PARALLEL
// Compile command line:
// $ make

// Execte command line:
// $ mpiexec.mpich -np 2  ./bin/POSL
