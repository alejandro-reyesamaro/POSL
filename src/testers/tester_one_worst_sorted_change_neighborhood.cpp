#include "tester_one_worst_sorted_change_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_worst_sorted_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_OneWorstSortedChangeNeighborhood::Tester_OneWorstSortedChangeNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_OneWorstSortedChangeNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(12,85));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //    config_ok ->    0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85
    vector<int> config( { 0, 2, 6, 24, 29, 32, 43, 55, 68, 75, 76, 85 } );

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), config);
    shared_ptr<OperationModule> op(make_shared<OM_OneWorstSortedNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    bool v = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;

        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_OneWorstSortedNeighborhood: OK !" : "OM_OneWorstSortedNeighborhood: fail :/";
}
