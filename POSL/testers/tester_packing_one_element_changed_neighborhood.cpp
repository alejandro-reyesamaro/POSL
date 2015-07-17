#include "tester_packing_one_element_changed_neighborhood.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "modules/om_one_element_changed_neighborhood.h"
#include "packing_neighborhood_tester.h"

Tester_PackingOneElementChangedNeighborhood::Tester_PackingOneElementChangedNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingOneElementChangedNeighborhood::test()
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
    OperationModule * op = new OM_OneElementChangedNeighborhood();
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);
    vector<int> pack = V->pack();
    POSL_Iterator<vector<int>> * it = V ->getIterator();

    PackingNeighborhoodTester * tester = new PackingNeighborhoodTester();
    return tester->test(sol, it, pack, "Packing One Element Changed Neighborhood");
}
