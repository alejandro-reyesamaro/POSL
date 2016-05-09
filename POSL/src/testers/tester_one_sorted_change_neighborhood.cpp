#include "tester_one_sorted_change_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_OneSortedChangeNeighborhood::Tester_OneSortedChangeNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_OneSortedChangeNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(12,85));
    //shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6,17));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //vector<int> config( { 0, 1, 4, 10, 12, 17 } );
    vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), config);
    shared_ptr<OperationModule> op(make_shared<OM_OneSortedChangeNeighborhood>(bench));
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    int ch = 0;
    bool v = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        ch = Tools::mismatches(neighbor, config);

        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;

        v = v && (ch <= 3 || ch >= 1);
        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_OneSortedChangedNeighborhood: OK !" : "OM_OneSortedChangedNeighborhood: fail :/";
}
