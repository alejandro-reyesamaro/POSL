#include "tester_tabuselection.h"

#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tabu_list.h"

#include <algorithm>

Tester_TabuSelection::Tester_TabuSelection(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_TabuSelection::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    vector<int> perm(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    });

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_1s());

    shared_ptr<OperationModule> op(make_shared<OM_GolfersSingleSwapNeighborhood>(bench));
    //PSP * psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V->getIterator();
    it->Reset();
    bool ok = true;

    TabuList tl(5);
    vector<int> co;
    for(int i = 0; i < 5; i++)
    {
        co = it->GetNext();
        tl.push(co);
    }

    ok = ok && tl.isTabu(co);

    sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), co);
    V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));
    /*
    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        is_permut = is_permut && is_permutation (perm.begin(), perm.end(), neighbor.begin()+16);
    }
    */
    return (ok) ? "Tabu Selection: OK !" : "Tabu Selection: fail :/";
}
