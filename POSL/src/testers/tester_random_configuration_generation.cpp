#include "tester_random_configuration_generation.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_random_conf_generation.h"
#include "../benchmarks/golfers.h"

Tester_RandomConfigurationGeneration::Tester_RandomConfigurationGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RandomConfigurationGeneration::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    OperationModule> op1(make_shared<OM_RandomConfGeneration>(bench));
    bool is_random = true;
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Solution> current_sol = static_pointer_cast<Solution>(op1->execute(psp, psp->GetBenchmark()->GetSolution()));
    for(int i = 0; i < 10; i++)
    {
        shared_ptr<Solution> new_sol = static_pointer_cast<Solution>(op1->execute(psp, psp->GetBenchmark()->GetSolution()));
        //cout << new_sol->configurationToString() << endl;
        is_random = is_random && (!current_sol->equal(new_sol));
    }
    return (is_random) ? "OM_RandomConfGeneration: OK !" : "OM_RandomConfGeneration: fail :/";
}
