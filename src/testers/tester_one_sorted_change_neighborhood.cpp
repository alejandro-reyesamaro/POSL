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
    //shared_ptr<Benchmark> bench(make_shared<GolombRuler>(12,85));
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(8,34));
    //shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6,17));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //vector<int> config( { 0, 1, 4, 10, 12, 17 } );
    vector<int> config( { 0, 1, 5, 8, 10, 17, 25, 34 } );
    //vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), config);
    shared_ptr<OperationModule> op(make_shared<OM_OneSortedChangeNeighborhood>(bench));
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    int ch = 0;
    bool v = true;
    int i_1;

    vector<bool> pv(13, false);
    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        ch = Tools::mismatches(neighbor, config);

        cout << "[ ";
        cout << neighbor[0] << " ";
        i_1 = neighbor[0];
        for(unsigned int i = 1; i < neighbor.size(); i++)
        {
            v = (!pv[neighbor[i] - i_1]);
            cout << neighbor[i] << " ";
            i_1 = neighbor[i];
        }
        cout << "]" << endl;

        v = v && (ch <= 3 || ch >= 1);
        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_OneSortedChangedNeighborhood: OK !" : "OM_OneSortedChangedNeighborhood: fail :/";
}
