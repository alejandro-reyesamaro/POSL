#include "tester_packing_golfers_permutation_neighborhood.h"
#include "../data/solution.h"
#include "../solver/psp.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "packing_neighborhood_tester.h"

Tester_PackingGolfersPermutationNeighborhood::Tester_PackingGolfersPermutationNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingGolfersPermutationNeighborhood::test()
{
    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });
    //PSP * psp = new PSP(bench);
    Solution * sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);
    OperationModule * op = new OM_GolfersSingleSwapNeighborhood();
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);
    vector<int> pack = V->pack();
    POSL_Iterator<vector<int>> * it = V ->getIterator();

    PackingNeighborhoodTester * tester = new PackingNeighborhoodTester();
    return tester->test(sol, it, pack, "Golfers Permutation Neighborhood");
}
