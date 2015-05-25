#include "tester_random_configuration_generation.h"
#include "data/solution.h"
#include "modules/operation_module.h"
#include "modules/om_random_conf_generation.h"

Tester_RandomConfigurationGeneration::Tester_RandomConfigurationGeneration()
{
}

string Tester_RandomConfigurationGeneration::test()
{

    OperationModule * op1 = new OM_RandomConfGeneration();
    bool is_random = true;
    for(int i = 0; i < 10; i++)
    {
        Solution * new_sol = (Solution *)op1->execute(bench, new Seed());
        //cout << new_sol->configurationToString() << endl;
        is_random = is_random && (!new_sol->equal(bench->solution));
        bench->UpdateSolution(new_sol);
    }
    return (is_random) ? "OM_RandomConfGeneration: OK !" : "OM_RandomConfGeneration: fail :/";
}
