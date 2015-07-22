#include "tester_random_configuration_generation.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_random_conf_generation.h"

Tester_RandomConfigurationGeneration::Tester_RandomConfigurationGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RandomConfigurationGeneration::test()
{

    OperationModule * op1 = new OM_RandomConfGeneration();
    bool is_random = true;
    //PSP * psp = new PSP(bench);
    Solution * current_sol = (Solution *)op1->execute(psp, psp->GetBenchmark()->GetSolution());
    for(int i = 0; i < 10; i++)
    {
        Solution * new_sol = (Solution *)op1->execute(psp, psp->GetBenchmark()->GetSolution());
        //cout << new_sol->configurationToString() << endl;
        is_random = is_random && (!current_sol->equal(new_sol));
    }
    return (is_random) ? "OM_RandomConfGeneration: OK !" : "OM_RandomConfGeneration: fail :/";
}