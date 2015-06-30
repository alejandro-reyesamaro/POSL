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
    //tests.push_back(new Tester_SetsIndexGenerator());
    tests.push_back(new Tester_MultiElementsChangedNeighborhood());

    for(unsigned int i = 0; i < tests.size(); i++)
        cout << ">> " << tests[i]->test() << endl;
}
