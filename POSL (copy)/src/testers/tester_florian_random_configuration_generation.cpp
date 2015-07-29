#include "tester_florian_random_configuration_generation.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_florian_random_conf_generation.h"

Tester_FlorianRandomConfigurationGeneration::Tester_FlorianRandomConfigurationGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_FlorianRandomConfigurationGeneration::test()
{
    OperationModule * op1 = new OM_FlorianRandomConfGeneration();
    bool is_random = true;
    //PSP * psp = new PSP(bench);
    for(int i = 0; i < 10; i++)
    {
        Solution * new_sol = (Solution *)op1->execute(psp, psp->GetCurrentSolution());
        is_random = is_random && (!new_sol->equal(psp->GetCurrentSolution()));
        psp->UpdateSolution(new_sol);
    }
    return (is_random) ? "OM_FlorianRandomConfGeneration: OK !" : "OM_FlorianRandomConfGeneration: fail :/";
}
