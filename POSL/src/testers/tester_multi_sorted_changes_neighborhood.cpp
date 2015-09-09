#include "tester_multi_sorted_changes_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_MultiSortedChangesNeighborhood::Tester_MultiSortedChangesNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_MultiSortedChangesNeighborhood::test()
{
    //Benchmark * bench(make_shared<GolombRuler(5, 11);
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(12, 85));
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    //vector<int> config( { 0, 1, 4, 9, 11 } );
    vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));

    shared_ptr<OperationModule> op(make_shared<OM_MultiSortedChangesNeighborhood>(bench));
    //PSP * psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();
    int ch  = 0;
    bool v  = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        ch = Tools::mismatches(neighbor, config);

        /*
        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;
        */
        v = v && (ch <= 3 || ch >= 1);
        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_MultiSortedChangesNeighborhood: OK !" : "OM_MultiSortedChangesNeighborhood: fail :/";
}
