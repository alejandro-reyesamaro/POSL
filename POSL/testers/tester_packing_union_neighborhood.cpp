#include "tester_packing_union_neighborhood.h"
#include "tester_packing_one_element_changed_neighborhood.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "modules/om_one_element_changed_neighborhood.h"
#include "modules/om_multi_elements_changed_neighborhood.h"
#include "packing_neighborhood_tester.h"
#include "operators/union_operator.h"
#include "modules/grouped_sequential_computation.h"

Tester_PackingUnionNeighborhood::Tester_PackingUnionNeighborhood()
{
}

string Tester_PackingUnionNeighborhood::test()
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
    PSP * psp = new PSP(bench);
    Solution * sol = new Solution(bench->GetSolution()->domains, config);
    OperationModule * m1 = new OM_OneElementChangedNeighborhood();
    OperationModule * m2 = new OM_MultiElementsChangedNeighborhood();

    Operator * op = new UnionOperator(m1, m2);
    CompoundModule * G1 = new GroupedSequentialComputation(op);

    Neighborhood * V = (Neighborhood *)G1->execute(psp, sol);
    int * pack = V->pack();
    POSL_Iterator<vector<int>> * it = V ->getIterator();
    PackingNeighborhoodTester * tester = new PackingNeighborhoodTester();
    return tester->test(bench, sol, it, pack, "Packing Union Neighborhood");
}
