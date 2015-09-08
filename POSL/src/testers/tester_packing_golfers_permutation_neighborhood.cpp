#include "tester_packing_golfers_permutation_neighborhood.h"
#include "../data/solution.h"
#include "../solver/psp.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../data/golfers_single_swap_neighborhood.h"
#include "packing_neighborhood_tester.h"
#include "../packing/packers/golfers_single_swap_packer.h"

Tester_PackingGolfersPermutationNeighborhood::Tester_PackingGolfersPermutationNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingGolfersPermutationNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);
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
    sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));
    shared_ptr<OperationModule> op(make_shared<OM_GolfersSingleSwapNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));
    shared_ptr<GolfersSingleSwapNeighborhood> N = static_pointer_cast<GolfersSingleSwapNeighborhood>(V);
    shared_ptr<GolfersSingleSwapPacker> p(make_shared<GolfersSingleSwapPacker>(config, N->size(), N->GetChanges()));
    vector<int> pack = p->pack();
    shared_ptr<POSL_Iterator<vector<int>>> it = V ->getIterator();

    shared_ptr<PackingNeighborhoodTester> tester(make_shared<PackingNeighborhoodTester();
    return tester->test(sol, it, pack, "Packing Golfers Permutation Neighborhood");
}
