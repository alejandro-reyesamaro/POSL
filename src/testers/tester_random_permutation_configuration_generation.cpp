#include "tester_random_permutation_configuration_generation.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"

#include <algorithm>

Tester_RandomPermutationConfigurationGeneration::Tester_RandomPermutationConfigurationGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RandomPermutationConfigurationGeneration::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<OperationModule> op1(make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench));
    bool is_random = true;
    bool is_permut = true;
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Solution> current_sol = static_pointer_cast<Solution>(op1->execute(psp, t_seed));
    //return current_sol->configurationToString();

    vector<int> perm;
    for(int j = 0; j < 16; j++)
        perm.push_back(j);

    for(int i = 0; i < 10; i++)
    {
        shared_ptr<Solution> new_sol = current_sol = static_pointer_cast<Solution>(op1->execute(psp, psp->GetBenchmark()->GetSolution()));
        //cout << new_sol->configurationToString() << endl;
        is_random =  is_random && (!current_sol->equal(new_sol));
        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), new_sol->get_conf_by_copy().begin());
        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), new_sol->get_conf_by_copy().begin()+16);
    }
    return (is_random) ? "OM_RandomConfPermutationByBlocksGeneration: OK !" : "OM_RandomConfPermutationByBlocksGeneration: fail :/";
}
