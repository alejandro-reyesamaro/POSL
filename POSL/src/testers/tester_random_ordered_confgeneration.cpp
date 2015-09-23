#include "tester_random_ordered_confgeneration.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_random_conf_ordered_generation.h"
#include "../benchmarks/golomb_ruler.h"

#include <algorithm>

Tester_RandomOrderedConfGeneration::Tester_RandomOrderedConfGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RandomOrderedConfGeneration::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(12,85));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    shared_ptr<OperationModule> op1(make_shared<OM_RandomConfOrderedGeneration>(bench));
    bool is_random = true;
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Solution> current_sol = static_pointer_cast<Solution>(op1->execute(psp, psp->GetBenchmark()->GetSolution()));
    for(int i = 0; i < 10; i++)
    {
        shared_ptr<Solution> new_sol = static_pointer_cast<Solution>(op1->execute(psp, psp->GetBenchmark()->GetSolution()));
        //cout << new_sol->configurationToString() << endl;
        is_random = is_random && (!current_sol->equal(new_sol));
        vector<int> conf = new_sol->GetConfiguration();
        is_random = is_random && is_sorted(conf.begin(), conf.end());
    }
    return (is_random) ? "OM_RandomConfOrderedGeneration: OK !" : "OM_RandomConfOrderedGeneration: fail :/";
}
