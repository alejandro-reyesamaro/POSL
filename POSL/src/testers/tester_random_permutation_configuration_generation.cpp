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
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    OperationModule * op1 = new OM_RandomConfPermutationByBlocksGeneration(bench);
    bool is_random = true;
    bool is_permut = true;
    //PSP * psp = new PSP(bench);
    Solution * current_sol = (Solution *)op1->execute(psp, psp->GetBenchmark()->GetSolution());
    //return current_sol->configurationToString();

    vector<int> perm;
    for(int j = 0; j < 16; j++)
        perm.push_back(j);

    for(int i = 0; i < 10; i++)
    {
        Solution * new_sol = (Solution *)op1->execute(psp, psp->GetBenchmark()->GetSolution());
        //cout << new_sol->configurationToString() << endl;
        is_random =  is_random && (!current_sol->equal(new_sol));
        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), new_sol->GetConfiguration().begin());
        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), new_sol->GetConfiguration().begin()+16);
    }
    return (is_random) ? "OM_RandomConfPermutationByBlocksGeneration: OK !" : "OM_RandomConfPermutationByBlocksGeneration: fail :/";
}
