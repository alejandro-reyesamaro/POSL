#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

/*
#include "testers/tester.h"
#include "testers/tester_cost_of_solution.h"
#include "testers/tester_random_configuration_generation.h"
#include "testers/tester_florian_random_configuration_generation.h"
#include "testers/tester_one_element_changed_neighborhood.h"
#include "testers/tester_first_improvement_selection.h"
#include "testers/tester_best_improvement_selection.h"
#include "testers/tester_rho_operator.h"
#include "testers/tester_cyclic_operator.h"
#include "testers/tester_sets_index_generator.h"
#include "testers/tester_multi_elements_changed_neighborhood.h"
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
*/

#include "testers/tester_union_operator.h"
#include "testers/tester_cost_of_solution.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<Tester *> tests;

/*
    tests.push_back(new Tester_CostOfSolution(argc, argv));
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
*/
    tests.push_back(new Tester_UnionOperator(argc, argv));

    for(unsigned int i = 0; i < tests.size(); i++)
        cout << ">> " << tests[i]->test() << endl;
}

// PARALLEL
// Compile command line:
// $ mpicc.mpich main.cpp -o main

// Execte command line:
// $ mpiexec.mpich -np 2 ./main
