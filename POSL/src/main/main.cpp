#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

/*
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
#include "testers/tester_solver_golfers.h"
#include "testers/tester_solver_golomb_ruler.h"
#include "testers/tester_solver_squaring_square.h"
*/
#include "../solver/for_golfers_css.h"
#include "../solver/for_squaring_square_css.h"
#include "../solver/for_golomb_ruler_css.h"
#include "../testers/tester_comunication.h"

#include "../solver/posl_meta_solver.h"

#include "mpi.h"

using namespace std;

int main(int argc, char **argv)
{

    vector<POSL_Solver *> solvers;
    Benchmark * bench;

    /* GOLFERS 
    bench = new Golfers(5,5,3);
    CreateSolverStrategy * css = new ForGolfersCSS();
    solvers = css->create();
    */

    /* SQUARING SQUARE */
    //vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    //bench = new SquaringSquare(10, squares);
    vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
    bench = new SquaringSquare(110, squares);
    CreateSolverStrategy * css = new ForSquaringSquareCSS();
    solvers = css->create();

    /* GOLOMB RULER 
    //bench = new GolombRuler(12,85);
    //bench = new GolombRuler(8,34);
    bench = new GolombRuler(9,44);
    CreateSolverStrategy * css = new ForGolombRulerCSS();
    solvers = css->create();
    */

    try
    {
        POSL_MetaSolver * s = new POSL_MetaSolver(solvers);
        s->solve(argc, argv, bench);
    }catch (const char* msg)
    {
         cout << msg << endl;
    }
}

int mainTest(int argc, char **argv)
{
    try
    {
        Tester_Comunication * s = new Tester_Comunication(argc, argv);
        s->test();
    }catch (const char* msg)
    {
         cout << msg << endl;
    }
}


// PARALLEL
// Compile command line:
// $ make

// Execute command line:
// $ mpiexec.mpich -np 2  ./bin/POSL