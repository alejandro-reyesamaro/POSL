#include "tester_golfers_permutation_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"

#include <algorithm>

Tester_GolfersPermutationNeighborhood::Tester_GolfersPermutationNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_GolfersPermutationNeighborhood::test()
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

    sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));

    shared_ptr<OperationModule> op(make_shared<OM_GolfersSingleSwapNeighborhood>(bench));
    //PSP * psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator<vector<int>>> it = V ->getIterator();
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
    return (is_permut) ? "OM_GolfersSingleSwapNeighborhood: OK !" : "OM_GolfersSingleSwapNeighborhood: fail :/";
}
