#include "tester_from_pack_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../data/golfers_single_swap_neighborhood.h"
#include "../data/from_pack_neighborhood.h"
#include "packing_neighborhood_tester.h"
#include "../packing/packers/golfers_single_swap_packer.h"

#include <algorithm>

Tester_FromPackNeighborhood::Tester_FromPackNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_FromPackNeighborhood::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    vector<int> perm(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    });

    sol = new Solution(psp->GetBenchmark()->Domains(), config);

    OperationModule * op = new OM_GolfersSingleSwapNeighborhood();
    //PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);
    GolfersSingleSwapNeighborhood * N = dynamic_cast<GolfersSingleSwapNeighborhood *>(V);
    GolfersSingleSwapPacker * p = new GolfersSingleSwapPacker(config, N->size(), N->GetChanges());
    vector<int> pack = p->pack();

    V = new FromPackNeighborhood(&pack[0]);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    bool is_permut = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        /*
        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            cout << *j << " ";
        }
        cout << "]" << endl;
        */
        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), neighbor.begin()+16);
    }
    return (is_permut) ? "FromPackNeighborhood: OK !" : "FromPackNeighborhood: fail :/";
}
