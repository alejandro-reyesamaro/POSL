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
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    shared_ptr<OperationModule> op1(make_shared<OM_RandomConfGeneration>(bench));
    shared_ptr<Operator> op(make_shared<FlorianOperator>(100, op1));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));

    bool is_random = true;
    //PSP * psp(make_shared<PSP(bench);
    for(int i = 0; i < 10; i++)
    {
        shared_ptr<Solution> new_sol = static_pointer_cast<Solution>(G->execute(psp, t_seed));
        is_random = is_random && (!new_sol->equal(sol));
        sol = new_sol;
    }
    return (is_random) ? "Florian Operator: OK !" : "Florian Operator: fail :/";
}
