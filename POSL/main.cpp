#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

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

using namespace std;

int main(int argc, char *argv[])
{
    vector<Tester *> tests;
    tests.push_back(new Tester_CostOfSolution());
    tests.push_back(new Tester_RandomConfigurationGeneration());
    tests.push_back(new Tester_FlorianRandomConfigurationGeneration());
    tests.push_back(new Tester_OneElementChangedNeighborhood());
    tests.push_back(new Tester_FirstImprovementSelection());
    tests.push_back(new Tester_BestImprovementSelection());
    tests.push_back(new Tester_RhoOperator());
    //tests.push_back(new Tester_CyclicOperator());
    tests.push_back(new Tester_SetsIndexGenerator());
    tests.push_back(new Tester_MultiElementsChangedNeighborhood());
    tests.push_back(new Tester_UnionOperator());
    tests.push_back(new Tester_ConditionalOperator());
    tests.push_back(new Tester_RandomSelection());
    tests.push_back(new Tester_SimulatedAnnealingDecition);
    tests.push_back(new Tester_BestImprovementTabuSelection());
    tests.push_back(new Tester_RandomPermutationConfigurationGeneration());

    for(unsigned int i = 0; i < tests.size(); i++)
        cout << ">> " << tests[i]->test() << endl;
}
