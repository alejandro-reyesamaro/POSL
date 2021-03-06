#include "tester_golfers_permutation_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_GolfersPermutationNeighborhood::Tester_GolfersPermutationNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_GolfersPermutationNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,4));    
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    vector<int> perm(
    {
        1,  2,   3,  4, //17,
        5,  6,   7,  8, //18,
        9,  10, 11, 12, //19,
        13, 14, 15, 16//, 20,
        //21, 22, 23, 24, 25
    });

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_444_c());

    shared_ptr<OperationModule> op(make_shared<OM_GolfersSingleSwapNeighborhood>(bench));
    //PSP * psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    vector<int> v = Tester::Golfers_444_c();
    cout << Tools::configurationToString(v) << endl;
    cout << "--"<<endl;

    shared_ptr<POSL_Iterator> it = V->getIterator();
    it->Reset();
    bool is_permut = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            cout << *j << ", ";
        }
        cout << "]" << endl;

        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), neighbor.begin()+16);
    }
    return (is_permut) ? "OM_GolfersSingleSwapNeighborhood: OK !" : "OM_GolfersSingleSwapNeighborhood: fail :/";
}
