#include "tester_packing_multi_changes_neighborhood.h"
#include "../data/solution.h"
#include "../solver/psp.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "packing_neighborhood_tester.h"
#include "../packing/packers/multi_changes_neighborhood_packer.h"

Tester_PackingMultiChangesNeighborhood::Tester_PackingMultiChangesNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingMultiChangesNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

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
    //PSP> psp(make_shared<PSP(bench);
    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), config);
    shared_ptr<OperationModule> op(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));
    shared_ptr<MultiElementsChangedNeighborhood> N = static_pointer_cast<MultiElementsChangedNeighborhood >(V);
    shared_ptr<MultiChangesNeighborhoodPacker> p(make_shared<MultiChangesNeighborhoodPacker>(config, N->size(), N->GetChanges()));
    vector<int> pack = p->pack();
    shared_ptr<POSL_Iterator> it = V ->getIterator();

    shared_ptr<PackingNeighborhoodTester> tester(make_shared<PackingNeighborhoodTester>());
    return tester->test(sol, it, pack, "Packing Multi Changes Neighborhood");
}
