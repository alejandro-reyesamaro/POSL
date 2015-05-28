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

    for(unsigned int i = 0; i < tests.size(); i++)
        cout << ">> " << tests[i]->test() << endl;
}
