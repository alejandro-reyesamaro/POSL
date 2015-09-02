#include "tester_florian_random_configuration_generation.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_random_conf_generation.h"
#include "../benchmarks/golfers.h"
#include "../operators/florian_operator.h"
#include "../modules/grouped_sequential_computation.h"

Tester_FlorianRandomConfigurationGeneration::Tester_FlorianRandomConfigurationGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_FlorianRandomConfigurationGeneration::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    OperationModule * op1 = new OM_RandomConfGeneration(bench);
    Operator * op = new FlorianOperator(op1);
    GroupedComputation * G = new GroupedSequentialComputation(op);

    bool is_random = true;
    //PSP * psp = new PSP(bench);
    for(int i = 0; i < 10; i++)
    {
        Solution * new_sol = (Solution *)G->execute(psp, sol);
        is_random = is_random && (!new_sol->equal(sol));
        sol = new_sol;
    }
    return (is_random) ? "Florian Operator: OK !" : "Florian Operator: fail :/";
}
